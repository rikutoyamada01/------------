/* アルゴリズムとデータ構造B
   3I 50番 氏名 山田陸斗 提出日：2025年10月27日
   #7 スタック（棚）
   スタックを操作する関数 Push(), Pop()を完成させる
   初期化用の関数 Initialize(), 表示用の関数 Display() を完成させる */

#include <stdio.h>

#define MAX 5 // スタックの容量
int stk[MAX]; // スタック本体
int ptr; // スタックポインタ

// 設問１：Push()の完成
int Push(int x) {
    if (ptr >= MAX) {
        return -1;
    }
    stk[ptr] = x;
    ptr++;
    return x;
}

// 設問２：Pop()の完成
int Pop() {
    if (ptr <= 0) {
        return -1;
    }
    ptr--;
    int tmp = stk[ptr];
    stk[ptr] = 0;
    return tmp;
}

// 設問３：Initialize()の完成
void Initialize()
{
    ptr = 0;
}

// 設問４：Display()の完成
void Display() {
    int i;
    for (i = 0; i < MAX; i++) { // スタックの上から下に for文を回す
        if (i == ptr) // スタックポインタの位置のとき PTR-> を出力
            printf("PTR->");
        else
            printf("     "); // 5文字分の空白を出力
        printf("stk[%d]: %d\n", i, stk[i]);
    }
    if (ptr == MAX) {
        printf("PTR->You can't push anymore\n");
    }
}

int main(void) {
    int menu = 1, x, i;
    // 設問５：スタックを初期化
    for (i = 0; i < MAX; i++) {
        stk[i] = 0;
    }

    while (menu) {  // menu の値で処理を変える
        printf("?Push(1) or Pop(0) = ");
        scanf("%d", &menu);
        if (menu == 1) {
            printf("?Push x = ");
            scanf("%d", &x);
            // 設問６：x の値をスタックにプッシュ
            x = Push(x);

            if (x == -1)
                printf("Stack full\n");
        } else if (menu == 0) {
            // 設問７：スタックから値をポップし x に代入
            x = Pop();

            if (x == -1)
                printf("Stack empty\n");
            else
                printf("%d was picked\n", x);
        }
        // 設問８：スタックの中身を表示
        Display();

        printf("?Continue(1) or Quit(0) = ");
        scanf("%d", &menu);
    }
}

/* 実行結果を以下に貼り付けて提出
?Push(1) or Pop(0) = 1
?Push x = 1
     stk[0]: 1
PTR->stk[1]: 0
     stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 
11
     stk[0]: 1
     stk[1]: 11
PTR->stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
     stk[0]: 1
     stk[1]: 11
     stk[2]: 1
PTR->stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
     stk[0]: 1
     stk[1]: 11
     stk[2]: 1
     stk[3]: 1
PTR->stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
     stk[0]: 1
     stk[1]: 11
     stk[2]: 1
     stk[3]: 1
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
Stack full
     stk[0]: 1
     stk[1]: 11
     stk[2]: 1
     stk[3]: 1
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 0
root@Ubuntu-24:~/アルゴリズムとデー
タ構造# ./7/ex07
?Push(1) or Pop(0) = 1
?Push x = 1
     stk[0]: 1
PTR->stk[1]: 0
     stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 11
     stk[0]: 1
PTR->stk[1]: 0
     stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
     stk[0]: 1
     stk[1]: 1
PTR->stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
PTR->stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 11
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
PTR->stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 11
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
Stack full
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
Stack full
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 11
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 
11
?Push(1) or Pop(0) = 1
?Push x = 1
Stack full
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 1
Stack full
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
     stk[4]: 1
PTR->You can't push anymore
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
1 was picked
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
     stk[3]: 11
PTR->stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
11 was picked
     stk[0]: 1
     stk[1]: 1
     stk[2]: 1
PTR->stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
1 was picked
     stk[0]: 1
     stk[1]: 1
PTR->stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
1 was picked
     stk[0]: 1
PTR->stk[1]: 0
     stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 2
?Push(1) or Pop(0) = 0
1 was picked
PTR->stk[0]: 0
     stk[1]: 0
     stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
Stack empty
PTR->stk[0]: 0
     stk[1]: 0
     stk[2]: 0
     stk[3]: 0
     stk[4]: 0
?Continue(1) or Quit(0) = 0
*/
