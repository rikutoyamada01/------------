#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Element {
    int data;
    struct Element *next;
};
struct Element *head;

// 課題5 ここから
void TracePQ(struct Element *p, struct Element *q) {
    struct Element *r;
    int i = 0;
    for (r = head; r != NULL; r = r->next, i++) {
        printf("%6d: %p %6d %p", i, r, r->data, r->next);
        if (r == p && r == q)
            printf(" <- p, q\n");
        else if (r == p)
            printf(" <- p\n");
        else if (r == q)
            printf(" <- q\n");
        else
            printf("\n");
    }
    printf("\n");
}

void Display(struct Element *q) {
    int i;
    struct Element *p;
    for (i = 0, p = head; p != NULL; i++, p = p->next) {
        printf("%6d: %p %6d %p", i, p, p->data, p->next);

        // 以下，変更箇所
        if (p == q)
            printf(" <- edited node\n");
        else
            printf("\n");
    }
    printf("\n");
}

void InsertFront(int x) {
    struct Element *p;
    p = malloc(sizeof(struct Element));
    p->data = x;
    p->next = head;
    head = p;

    // printf("先頭にノードを挿入した後のリスト\n");
    Display(p); // Display の呼び出し
}

int Remove(int x) {
    int i;
    struct Element *p, *q;
    for (i = 0, p = q = head; p != NULL; i++, q = p, p = p->next) {

        // リスト全体＋p, q の表示
        TracePQ(p, q);

        if (p->data == x) {
            if (p == head) {
                head = p->next;
                free(p);
            } else {
                q->next = p->next;
                free(p);
            }

            // printf("ノードを削除した後のリスト\n");
            Display(q); // Display の呼び出し

            return i;
        }
    }
    return -1;
}

void InsertbyIndex(int index, int x) {
    if (head == NULL || index == 0)
        InsertFront(x); // リストの先頭に挿入
    else {
        int i, j;       // j未使用（TracePQ()を関数化したため）
        struct Element *p, *q, *r;
        for (i = 0, p = q = head; i < index && p->next != NULL; i++, q = p, p = p->next) {
            // リスト全体＋p, q の表示
            printf("i = %d\n", i);
            TracePQ(p, q);
        }

        // リスト全体＋p, q の表示
        // for 文が終わった後に一度表示しないと，p, q の最終的な位置が表示されない
        printf("i = %d\n", i);
        TracePQ(p, q);

        r = malloc(sizeof(struct Element));
        r->data = x;
        if (i == index) { // 間（index番目）に挿入
            q->next = r;
            r->next = p;
        } else { // 末尾に挿入
            p->next = r;
            r->next = NULL;
        }

        // printf("index番目にノードを挿入した後のリスト\n");
        Display(r); // Display の呼び出し
    }
}
// 課題5 ここまで

// 課題6 ここから
// 問題１－１　末尾に挿入 ※この処理（アルゴリズム）が必要かは要検討（データ構造に工夫の余地あり）
void InsertRear(int x) {
    if (head == NULL)     // 問題１－１-1　リストが空のとき、先頭に挿入
    InsertFront(x);

    else {
        struct Element *p, *r;  // qは不要

        for (p = head; p->next != NULL; p = p->next) continue; // 問題１－１-2　末尾ノードを探す

        r = malloc(sizeof(struct Element));
        r->data = x;
        // 問題１－１-3　正しくリンクする
        p->next = r;
        r->next = NULL;

        // 問題１－１-4　正しく追加ノードを表示する
        Display(r);
    }
}
// 問題１－２　先頭を削除
void RemoveFront() {        // 戻り値の型は要検討
    if (head != NULL) {     // リストが空でないときのみ処理する
        struct Element *p;  // あとでfree()するために利用
        p = head;
        head = head->next;   // 問題１－２-1　正しくリンクする

        free(p);         // 問題１－２-2　削除する要素をfree()する

        Display(head);
    }
}
// 問題１－３　末尾を削除   ※単方向リストの不便さを体感する演習（双方向リストは自習）
void RemoveRear() {                // 戻り値の型は要検討
    if (head != NULL) {            // リストが空でないときのみ処理する
        if (head->next == NULL)    // 問題１－３-1　ノードが一つだけであれば先頭を削除
            RemoveFront();
        else {
            struct Element *p, *q; // pは実質、free()のために利用
            for (p = q = head; p->next != NULL; q = p, p = p->next) continue;
            // 問題１－３-1　正しくリンクする
            q->next = NULL;
            // 問題１－３-2　削除する要素をfree()する
            free(p);
            Display(q);
        }
    }
}
// 問題２　リストを空にする ※初期化とは異なる
void Clear() {
    while (head != NULL) {  // 問題２-1　リストが空になるまで
        printf("     free data:%d, address:%p\n", head->data, head);
        // 問題２-2　先頭を削除
        RemoveFront();
    }
}

// 以下、修正不要（読む必要はある）
void Initialize() { //プログラム起動時以外は呼び出さない
    head = NULL;
}

/*
void insert_sort(int data) {
    struct Element *p, *q, *r;
    if (head == NULL) {
        p = malloc(sizeof(struct Element));
        p->data = data;
        p->next = head;
        head = p;
        Display(p);
    } else {
        for (p = q = head; p != NULL && p->data < data; q = p, p = p->next);
        //for (p = q = head; p->data < data && p->next != NULL ; q = p, p = p->next);
        r = malloc(sizeof(struct Element));
        r->data = data;
        if (p == head) {
            r->next = p;
            head = r;
        } else {
            r->next = p;
            q->next = r;
        }
        Display(r);
    }
}

// void reverse_list(){
//     struct Element *p, *q, *r;
//     printf("hogehoge\n");
//     p = q = head;
//     while (p != NULL) {
//         r = p;
//         p = p->next;
//         if (r == head)
//             r->next = NULL;
//         else
//             r->next=q;
//         q = r;
//     }
//     head = q;
// }

void reverse_list() {
    struct Element *p, *q;
    for (p = q = head; p != NULL; q = p) {
        p = p->next;
        if (q == head)
            q->next = NULL;
        else
            q->next = head;
        head = q;
    }
}
*/

int main() {
    Initialize();

    // 問題３　設問なし
    // 乱数のシードをtimeを使って設定する
    srand((unsigned)time(NULL));

    int i, x;
    printf("ノード数5の線形リストの作成\n");
    for (i = 0; i < 3; i++) {
        // シードに従って100より小さい乱数を生成して int x に代入する
        x = rand() % 100;
        printf("挿入するノードのデータ = %d\n", x);
        InsertRear(x);
    }
    x = rand() % 100;
    printf("挿入するノードのデータ = %d\n", x);
    InsertbyIndex(0, x);
    x = rand() % 100;
    printf("挿入するノードのデータ = %d\n", x);
    InsertbyIndex(3, x);


    printf("----------\n");
    printf("RemoveFront() で先頭のノードを削除\n");
    RemoveFront();

    printf("----------\n");
    printf("RemoveRear() で末尾のノードを削除\n");
    RemoveRear();

    printf("----------\n");
    printf("Clear() で全ノードを削除\n");
    Clear();
    printf("\n");
    printf("----------\n");
    printf("head = %p\n", head);

    return 0;
}
// 課題6 ここまで
