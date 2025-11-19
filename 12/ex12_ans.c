/* アルゴリズムとデータ構造B
   3I ○番 氏名 提出日：
   #12 線形リストの操作
   設問 Initialize(), InsertFront(), Remove(), InsertbyIndex(), Search() を作成する */

#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element *next;
};
struct Element *head;

// 設問１：リストの基本処理のための関数を作成
void Initialize() {
    head = NULL;
}

void InsertFront(int x) {
    struct Element *p;
    p = malloc(sizeof(struct Element));
    p->data = x;
    p->next = head;
    head = p;
}

int Remove(int x) {
    int i;
    struct Element *p, *q;
    for (i = 0, p = q = head; p != NULL; i++, q = p, p = p->next) {
        if (p->data == x) {
            if (p == head){
                head = p->next;
                free(p);
            } else {
                q->next = p->next;
                free(p);
            }
            return i;
        }
    }
    return -1;
}

void InsertbyIndex(int index, int x) {
    if (head == NULL || index == 0)
        InsertFront(x); // リストの先頭に挿入
    else {
        int i;
        struct Element *p, *q;
        for (i = 0, p = q = head; i < index && p->next != NULL; i++, q = p, p = p->next);
        struct Element *r;
        r = malloc(sizeof(struct Element));
        r->data = x;
        if (i == index) { // 間（index番目）に挿入
            q->next = r;
            r->next = p;
        } else { // 末尾に挿入
            p->next = r;
            r->next = NULL;
        }
    }
}

int Search(int x) {
    struct Element *p;
    int i;
    for (p=head, i=0; p!=NULL; p=p->next, i++){
        if (p->data == x)
            return i;
    }
    return -1; // 探索失敗
}

// Displayは変更の必要はない
void Display() {
    if (head == NULL)
        printf("list is empty\n");
    else {
        int i;
        struct Element *p;
        for (i=0, p=head; p!=NULL; i++, p=p->next)
            printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
    }
}

int main(void) {
    int mode = 1;
    // 設問２：線形リストの初期化（関数の呼び出し）
    Initialize();
    while (mode) {
        printf("list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = ");
        scanf("%d", &mode);
        if (mode == 1) { // 先頭へのノードの挿入
            int x;
            printf("挿入するノードのデータを入力してください：");
            scanf("%d", &x);
            // 設問３：先頭へのノードの挿入を実行（関数の呼び出し）
            InsertFront(x);
        } else if (mode == 2) { // ノードの挿入
            int x, index;
            printf("ノードを挿入する位置（0以上の値）を入力してください：");
            scanf("%d", &index);

            if (index < 0) {
                printf("indexが無効です\n");
                continue;
            }

            printf("挿入するノードのデータを入力してください：");
            scanf("%d", &x);
            // 設問４：ノードの挿入を実行（関数の呼び出し）
            InsertbyIndex(index, x);
        } else if (mode == 3) { // ノードの探索
            int x, index;
            printf("探索するノードのデータを入力してください：");
            scanf("%d", &x);
            // 設問ｘ：ノードの探索を実行（index = ??; の形で関数の呼び出し）（12回目の演習ではやらなくて良い）
            index = Search(x);
            if(index == -1)
                printf("データ %d のノードは見つかりませんでした\n", x);
            else
                printf("データ %d のノードは %d 番目に見つかりました\n", x, index);
        } else if (mode == 0) { // ノードの削除
            int x;
            printf("削除するノードのデータを入力してください：");
            scanf("%d", &x);
            if (Remove(x) == -1)
                printf("データ %d のノードは見つかりませんでした\n", x);
        }
        Display();
        printf("?Continue(1) or Quit(0) = ");
        scanf("%d", &mode);
    }

    return 0;
}

/* 実行結果を以下に貼り付けて提出
   InsertFront(), Remove()（先頭の削除，それ以外の削除）, InsertbyIndex()（先頭への挿入，末尾への挿入，間への挿入） の動作確認
❯ ./ex12
list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = 1
挿入するノードのデータを入力してください：10
     0: 0x559262ad8ac0     10 (nil)
?Continue(1) or Quit(0) = 1
list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = 2
ノードを挿入する位置（0以上の値）を入力してください：-1
indexが無効です
list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = 2
ノードを挿入する位置（0以上の値）を入力してください：0
挿入するノードのデータを入力してください：20
     0: 0x559262ad8ae0     20 0x559262ad8ac0
     1: 0x559262ad8ac0     10 (nil)
?Continue(1) or Quit(0) = 1
list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = 2
ノードを挿入する位置（0以上の値）を入力してください：1
挿入するノードのデータを入力してください：30
     0: 0x559262ad8ae0     20 0x559262ad8b00
     1: 0x559262ad8b00     30 0x559262ad8ac0
     2: 0x559262ad8ac0     10 (nil)
?Continue(1) or Quit(0) = 1
list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = 2
ノードを挿入する位置（0以上の値）を入力してください：100
挿入するノードのデータを入力してください：40
     0: 0x559262ad8ae0     20 0x559262ad8b00
     1: 0x559262ad8b00     30 0x559262ad8ac0
     2: 0x559262ad8ac0     10 0x559262ad8b20
     3: 0x559262ad8b20     40 (nil)
?Continue(1) or Quit(0) = 1
list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = 0
削除するノードのデータを入力してください：20
     0: 0x559262ad8b00     30 0x559262ad8ac0
     1: 0x559262ad8ac0     10 0x559262ad8b20
     2: 0x559262ad8b20     40 (nil)
?Continue(1) or Quit(0) = 1
list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = 0
削除するノードのデータを入力してください：10
     0: 0x559262ad8b00     30 0x559262ad8b20
     1: 0x559262ad8b20     40 (nil)
?Continue(1) or Quit(0) = 1
list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = 0
削除するノードのデータを入力してください：40
     0: 0x559262ad8b00     30 (nil)
?Continue(1) or Quit(0) = 0
*/
