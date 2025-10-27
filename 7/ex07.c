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
}

// 設問２：Pop()の完成
int Pop() {
}

// 設問３：Initialize()の完成
void Initialize()
{
    // スタックポインタの値を初期化
}

// 設問４：Display()の完成
void Display() {
    int i;
    for () { // スタックの上から下に for文を回す
        if (i == ptr) // スタックポインタの位置のとき PTR-> を出力

        else
            printf("     "); // 5文字分の空白を出力
    // 要素番号とスタックの値を出力
    }
}

int main(void) {
    int menu = 1, x;
    // 設問５：スタックを初期化

    while (menu) {  // menu の値で処理を変える
        printf("?Push(1) or Pop(0) = ");
        scanf("%d", &menu);
        if (menu == 1) {
            printf("?Push x = ");
            scanf("%d", &x);
            // 設問６：x の値をスタックにプッシュ

            if (x == -1)
                printf("Stack full\n");
        } else if (menu == 0) {
            // 設問７：スタックから値をポップし x に代入

            if (x == -1)
                printf("Stack empty\n");
            else
                printf("%d was picked\n", x);
        }
        // 設問８：スタックの中身を表示

        printf("?Continue(1) or Quit(0) = ");
        scanf("%d", &menu);
    }
}

/* 実行結果を以下に貼り付けて提出
   （データが正しく pop, push される，
   スタックが FULL / EMPTY の場合にそれぞれエラー表示がされることを確認）

*/
