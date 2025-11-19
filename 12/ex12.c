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

}

void InsertFront(int x) {
    struct Element   p;
    p = malloc(sizeof(          ));
    p->data =         ;
    p->next =         ;
    head =            ;
}

int Remove(int x) {
    int i;                    // i利用
    struct Element *p, *q;    // q利用
    // 削除する要素が何番目にあるかを探索する
    for (;;) {
        if (p->data = x) { // 見つかったとき
            // 場合分けに注意して、要素を削除し、iを返す
            
            return i;
        }
    }
    // 見つからなかったとき
    return -1;
}

void InsertbyIndex(int index, int x) {
    // リストが空、または、indexが0のとき、先頭に追加 => InsertFront()利用
    if (head ==           || index ==           )
        InsertFront(        );
    else {
        int i;                    // i利用
        struct Element *p, *q;    // q利用
        // 追加する要素（pの次に挿入を想定）までカウントする continue文を利用するとよい
        for (;;) ;
        // rに新しい要素を生成
        struct Element *r;
        r =                        ;
        r->data = x;
        // 間に挿入と、末尾に挿入を場合分け
        if (                  ) {
            
            
        } else {
            
            // コメント 末尾に挿入はpがNULLであると見ると、実は場合分け不要（ループの継続条件は変わる）
        }
    }

}

// 12回目の演習では　search は作成しなくて良い
// int Search(int x)
// {
// }

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
    int menu = 1;
    // 設問２：線形リストの初期化（関数の呼び出し）

    while (menu) {
        printf("list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = ");
        scanf("%d", &menu);
        if (menu == 1) { // 先頭へのノードの挿入
            int x;
            printf("挿入するノードのデータを入力してください：");
            scanf("%d", &x);
            // 設問３：ノードの追加を実行（関数の呼び出し）

        } else if (menu == 2) { // ノードの挿入
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

        } else if (menu == 3) { // ノードの探索
            int x, index;
            printf("探索するノードのデータを入力してください：");
            scanf("%d", &x);
            // 設問ｘ：ノードの探索を実行（index = ??; の形で関数の呼び出し）（12回目の演習ではやらなくて良い）

            if (index == -1)
                printf("データ %d のノードは見つかりませんでした\n", x);
            else
                printf("データ %d のノードは %d 番目に見つかりました\n", x, index);
        } else if (menu == 0) { // ノードの削除
            int x;
            printf("削除するノードのデータを入力してください：");
            scanf("%d", &x);
            if (Remove(x) == -1)
                printf("データ %d のノードは見つかりませんでした\n", x);
        }
        Display();
        printf("?Continue(1) or Quit(0) = ");
        scanf("%d", &menu);
    }

    return 0;
}

/* 実行結果を以下に貼り付けて提出
   InsertFront(), Remove()（先頭の削除，それ以外の削除）, InsertbyIndex()（先頭への挿入，末尾への挿入，間への挿入） の動作確認
*/
