/* アルゴリズムとデータ構造B
   3I ○番 氏名 提出日：
   #15 線形リストによるスタック，キューの実現
   設問：Push(), Pop(), Enque(), Deque() の作成 */

#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element *next;
};
struct Element *head, *tail;  // tail が追加されていることに注意

void Initialize() {
    head = tail = NULL;  // tail = NULL が追加されていることに注意
}

// 設問 １：スタックの入出力関数 Push, Pop を作成
void Push(int x) {
    struct Element *p;
    p = malloc(sizeof(struct Element));
    p->data = x;
    p->next = head;
    head = p;
}

int Pop() {
    if (head == NULL) // スタックが空
        return -1;
    else {
        struct Element *p;
        int x;
        p = head;
        x = p->data;  // 先頭データをxに取り出す（x = head->data; でもOK）
        head = p->next;  // 先頭を次のノードに（head = head->next; でもOK）
        free(p);  // 元の先頭を解放（このために p = head; が必要）
        return x;
    }
}

// 設問 2：キューの入出力関数 Enque, Deque を作成
void Enque(int x) {
    struct Element *p;
    p = malloc(sizeof(struct Element));
    p->data = x;

    if (head == NULL)  // キューが空のとき
        head = p;  // 新しいノードが先頭になる（※末尾でもある）
    else
        tail->next = p;  // 現在の末尾ノードの次を新しいノードに

    tail = p;  // 新しいノードを末尾ノードにする
    tail->next = NULL;  // 末尾ノードのnextをNULLに
}

int Deque() {
    if (head == NULL)
        return -1;
    else {
        struct Element *p;
        int x;
        p = head;
        x = p->data;
        head = p->next;
        free(p);
        return x;
    }
}

void Display() {  // 変更しない
    int i;
    struct Element *p;
    for (i=0, p=head; p!=NULL; i++, p=p->next)
        printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
}

int main() {
    int menu = 1, x, s_or_q;
    Initialize();

    printf("?Stack(1) or Queue(2) = ");
    scanf("%d", &s_or_q);

    while (menu) {
        printf("?Input(1) or Output(2) = ");
        scanf("%d", &menu);
        if (menu == 1) {
            printf("?Input x = ");
            scanf("%d", &x);
            if (s_or_q == 1)
                Push(x);  // スタック
            else
                Enque(x);  // キュー
        } else if (menu == 2) {
            if (s_or_q == 1)
                x = Pop();  // スタック
            else
                x = Deque();  // キュー
            if (x == -1) {  // リストが空
                printf("empty\n");
            } else {
                printf("%d was picked\n", x);
            }
        }

        Display();
        printf("?Continue(1) or Quit(0) = ");
        scanf("%d", &menu);
    }

    return 0;
}

/* 実行結果を以下に貼り付けて提出
   スタック，キュー の動作を確認する
❯ ./ex15
?Stack(1) or Queue(2) = 1
?Input(1) or Output(2) = 1
?Input x = 10
     0: 0x60000104c000     10 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 1
?Input x = 20
     0: 0x600001040040     20 0x60000104c000
     1: 0x60000104c000     10 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 1
?Input x = 30
     0: 0x60000104c010     30 0x600001040040
     1: 0x600001040040     20 0x60000104c000
     2: 0x60000104c000     10 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
30 was picked
     0: 0x600001040040     20 0x60000104c000
     1: 0x60000104c000     10 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
20 was picked
     0: 0x60000104c000     10 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
10 was picked
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
empty
?Continue(1) or Quit(0) = 0
❯ ./ex15
?Stack(1) or Queue(2) = 2
?Input(1) or Output(2) = 1
?Input x = 10
     0: 0x6000031bc000     10 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 1
?Input x = 20
     0: 0x6000031bc000     10 0x6000031bc010
     1: 0x6000031bc010     20 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 1
?Input x = 30
     0: 0x6000031bc000     10 0x6000031bc010
     1: 0x6000031bc010     20 0x6000031bc020
     2: 0x6000031bc020     30 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
10 was picked
     0: 0x6000031bc010     20 0x6000031bc020
     1: 0x6000031bc020     30 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
20 was picked
     0: 0x6000031bc020     30 0x0
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
30 was picked
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
empty
?Continue(1) or Quit(0) = 0
*/
