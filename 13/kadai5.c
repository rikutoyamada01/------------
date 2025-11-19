#include <stdio.h>
#include <stdlib.h>

#define N 10

struct Element {
    int data;
    struct Element *next;
};
struct Element *head;

// 問題１ リスト全体＋p, q の表示
void TracePQ(struct Element *p, struct Element *q) {  //試験レベルでは、引数を考える設問もありえます
    struct Element *r;
    int i = 0;
    for (r = head; r != NULL; r = r->next, i++) {
        printf("%6d: %p %6d %p", i, r, r->data, r->next);
        if (                   )
            printf(" <- p, q\n");
        else if (              )
            printf(" <- p\n");
        else if (              )
            printf(" <- q\n");
        else
            printf("\n");
    }
    printf("\n");
}

void Display(struct Element *q) {  //試験レベルでは、引数を考える設問もありえます
    if (head == NULL)
        printf("list is empty\n");
    else {
        int i;
        struct Element *p;
        for (i = 0, p = head; p != NULL; i++, p = p->next) {
            printf("%6d: %p %6d %p", i, p, p->data, p->next);

            // 問題２
            if (          )
                printf(" <- edited node\n");
            else
                printf("\n");
        }
        printf("\n");
    }
}

void InsertFront(int x) {
    struct Element *p;
    p = malloc(sizeof(struct Element));
    p->data = x;
    p->next = head;
    head = p;

    // 問題２
    printf("先頭にノードを挿入した後のリスト\n");
    Display(       ); // Display の呼び出し
}

int Remove(int x) {
    int i;
    struct Element *p, *q;
    for (i = 0, p = q = head; p != NULL; i++, q = p, p = p->next) {

        // 問題１ リスト全体＋p, q の表示
                  (p, q);

        if (p->data == x) {
            if (p == head) {
                head = p->next;
                free(p);
            } else {
                q->next = p->next;
                free(p);
            }

            // 問題２
            printf("ノードを削除した後のリスト\n");
            Display(       ); // Display の呼び出し

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
        for (i = 0, p = q = head; i < index && p->next != NULL; i++, q = p, p = p->next) {
           // 問題１ リスト全体＋p, q の表示
           TracePQ(        );
        }

        // リスト全体＋p, q の表示
        // for 文が終わった後にも一度表示しないと，p, q の最終的な位置が表示されない
        TracePQ(p, q);

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

        // 問題２
        printf("index番目にノードを挿入した後のリスト\n");
        Display(       ); // Display の呼び出し
    }
}

// 以下、修正不要
void Initialize() {
    head = NULL;
}

int main () {
    int mode = 1;
    Initialize(); // 初期化

    // デモ実行用にノード生成・表示
    for(int i = 0; i < N; i++)
        InsertFront((i+1)*10);
    Display(NULL);

    while (mode) {
        printf("list process ?InsertFront(1), InsertbyIndex(2), Search(3) or Remove(0) = ");
        scanf("%d", &mode);
        if (mode == 1) { // 先頭へのノードの挿入
            int x;
            printf("挿入するノードのデータを入力してください：");
            scanf("%d", &x);
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
            InsertbyIndex(index, x);
        // } else if (mode == 3) { // ノードの探索
        //     int index;
        //     printf("?data = ");
        //     scanf("%d", &id);
        //     // index = search(id);
        //     if(index == -1){
        //         printf("data = %d was not found\n", id);
        //     }else{
        //         printf("data = %d was found at %d\n", id, index);
        //     }
        } else if (mode == 0) { // ノードの削除
            int x;
            printf("削除するノードのデータを入力してください：");
            scanf("%d", &x);
            if (Remove(x) == -1)
                printf("データ %d のノードは見つかりませんでした\n", x);
        }
        // Display();
        printf("?Continue(1) or Quit(0) = ");
        scanf("%d", &mode);
    }

    return 0;
}
