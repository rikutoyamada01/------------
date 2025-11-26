/* アルゴリズムとデータ構造B
   3I 50番 氏名 山田陸斗 提出日：2025/11/26
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
//          ex12のInsertFront()参考
void Push(int x) {
    struct Element *p;
    p = malloc(sizeof(struct Element *));
    p->data = x;
    p->next = head;
    head = p;
}
//          kadai6のRemoveFront()参考
int Pop() {
    if (head != NULL){
        int x;
        struct Element *p;
        p = head;
        head = head->next;
        x = p->data;
        free(p);
        return x;
    } else {
        return -1;
    }
}

// 設問 2：キューの入出力関数 Enque, Deque を作成
void Enque(int x) {
    struct Element *p;
    p = malloc(sizeof(struct Element *));
    p->data = x;

    if (head == NULL)
        head = p;
    else
        tail->next = p;

    tail = p;
    p->next = NULL;
}
//          スタックのPop()と同一
int Deque() {
    int x;
    x = Pop();
    return x;
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
?Stack(1) or Queue(2) = 1
?Input(1) or Output(2) = 1
?Input x = 32
     0: 0x5f89b734dac0     32 (nil)
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 1
?Input x = 432
     0: 0x5f89b734dae0    432 0x5f89b734dac0
     1: 0x5f89b734dac0     32 (nil)
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
432 was picked
     0: 0x5f89b734dac0     32 (nil)
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
32 was picked
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
empty
?Continue(1) or Quit(0) = 0



?Stack(1) or Queue(2) = 2
?Input(1) or Output(2) = 1
?Input x = 53
     0: 0x5a741c121ac0     53 (nil)
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 1
?Input x = 6 
     0: 0x5a741c121ac0     53 0x5a741c121ae0
     1: 0x5a741c121ae0      6 (nil)
?Continue(1) or Quit(0) = 1
?Input(1) or Output(2) = 2
53 was picked
     0: 0x5a741c121ae0      6 (nil)
?Continue(1) or Quit(0) = 2
?Input(1) or Output(2) = 2
6 was picked
?Continue(1) or Quit(0) = 2
?Input(1) or Output(2) = 2
empty
?Continue(1) or Quit(0) = 0
*/
