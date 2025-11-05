/* アルゴリズムとデータ構造B
   3I ○番 氏名 提出日：
   #9 キュー（待ち行列）
   キューを操作する関数 Enque(), Deque()を完成させる
   初期化用の関数 Initialize(), 表示用の関数 Display() を完成させる */

#include <stdio.h>

#define MAX 5 // キューの容量
int que[MAX]; // キュー本体
int front, rear; // 先頭要素，末尾要素の位置
int num;  // 現在のデータ数

// 設問１：Enqueの完成
int Enque(int x) {
    if (front == rear & que[front] != 0)
        return -1;

    que[front] = x;
    front++;
    num++;
    if (front == MAX)
        front = 0;
    return x;
}

// 設問２：Dequeの完成
int Deque() {
    if (front == rear & que[rear] == 0)
        return -1;

    int tmp = que[rear];
    que[rear] = 0;
    rear++;
    num--;
    if (rear == MAX)
        rear = 0;
    return tmp;
}

// 設問３：Initializeの完成（front, rear, num の値の初期化）
void Initialize() {
    front = rear = 0;
    num = 0;
}

// 設問４：Displayの完成
void Display() {
    int i;
    // キューの(イメージ的に)左から右に for文を回す
    for (i=0;i<MAX;i++) {
        // front の位置には front-> と出力．でなければスペース
        if (i == front)
            printf(" front->");
        else
            printf("        ");
        // 要素番号とキューの値を出力
        printf("%d", que[i]);

        // rear の位置には <-rear と出力．でなければスペース
        if (i == rear)
            printf("  <-rear\n");
        else
            printf("        \n");
    }
}

int main(void) {
    int menu = 1, x;
    // 設問５：キューを初期化

    while (menu) {  // menu の値で処理を変える
        printf("?Enque(1) or Deque(0) = ");
        scanf("%d", &menu);
        if (menu == 1) {
            printf("?Enque x = ");
            scanf("%d", &x);
            // 設問６：x の値をエンキュー
            x = Enque(x);

            if (x == -1)
                printf("Queue full\n");
        } else if (menu == 0) {
            // 設問７：キューから値をデキュー
            x = Deque(x);

            if (x == -1)
                printf("Queue empty\n");
            else
                printf("%d was picked\n", x);
        }
        // 設問８：キューの中身を表示
        Display();

        printf("?Continue(1) or Quit(0) = ");
        scanf("%d", &menu);
    }

    return 0;
}

/* 実行結果を以下に貼り付けて提出
   （データが正しく入追加・取り出すことができる，
   キューが FULL / EMPTY の場合に，それぞれエラー表示がされる，
   front / rear が配列の範囲を超えたとき，0 に戻ることを確認）

*/
