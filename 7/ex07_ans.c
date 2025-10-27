/* アルゴリズムとデータ構造B
   3I ○番 氏名 提出日：
   #7 スタック（棚）
   スタックを操作する関数 Push(), Pop()を完成させる
   初期化用の関数 Initialize(), 表示用の関数 Display() を完成させる */

#include <stdio.h>

#define MAX 5 // スタックの容量
int stk[MAX]; // スタック本体
int ptr; // スタックポインタ

// 設問１：Push()の完成
int Push(int x) {
    // ずらしてから入れる
    if (ptr < MAX-1)
        stk[++ptr] = x;
    else
        return -1;

    return 0;
}

// 設問２：Pop()の完成
int Pop() {
    // 出してからずらす
    if (ptr >= 0)
        return stk[ptr--];
    else {
        return -1;
    }
}

// 設問３：Initialize()の完成
void Initialize() {
    // スタックポインタの値を初期化
    ptr = -1; // ずらしてから入れるため，-1 で初期化
}

// 設問４：Display()の完成
void Display() {
    int i;
    for (i = MAX-1; i >= 0; i--) { // スタックの上から下に for文を回す
        if (i == ptr) // スタックポインタの位置のとき PTR-> を出力
            printf("PTR->");
        else
            printf("     ");
        // 要素番号とスタックの値を出力
        printf("%6d: %6d\n", i, stk[i]);
    }
}

int main(void) {
    int menu = 1, x;
    // 設問５：スタックを初期化
    Initialize();
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
   （データが正しく pop, push される，
   スタックが FULL / EMPTY の場合にそれぞれエラー表示がされることを確認）
❯ ./ex7
?Push(1) or Pop(0) = 1
?Push x = 10
          4:      0
          3:      0
          2:      0
          1:      0
PTR->     0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 20
          4:      0
          3:      0
          2:      0
PTR->     1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 30
          4:      0
          3:      0
PTR->     2:     30
          1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 40
          4:      0
PTR->     3:     40
          2:     30
          1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 50
PTR->     4:     50
          3:     40
          2:     30
          1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 1
?Push x = 60
Stack full
PTR->     4:     50
          3:     40
          2:     30
          1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
50 was picked
          4:     50
PTR->     3:     40
          2:     30
          1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
40 was picked
          4:     50
          3:     40
PTR->     2:     30
          1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
30 was picked
          4:     50
          3:     40
          2:     30
PTR->     1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
20 was picked
          4:     50
          3:     40
          2:     30
          1:     20
PTR->     0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
10 was picked
          4:     50
          3:     40
          2:     30
          1:     20
          0:     10
?Continue(1) or Quit(0) = 1
?Push(1) or Pop(0) = 0
Stack empty
          4:     50
          3:     40
          2:     30
          1:     20
          0:     10
?Continue(1) or Quit(0) = 0
*/
