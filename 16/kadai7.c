#include <stdio.h>
#include <stdlib.h>

// 問題１　これまでの演習・課題で作成したプログラム（主にex15.c）を参考にchar型の処理ができるように修正する

struct Element {
    // 問題１-1　正しいデータ型で定義する
            data;
    struct Element *next;
};
struct Element *head, *tail;  // キューなのでtail必要

void Initialize() {
	head = tail = NULL;
}
// 問題１-2　Enque()を参考にして正しく動作するように修正する
void Enque_char(        x) {

}
// 問題１-3　Deque()を参考にして正しく動作するように修正する
        Deque_char() {

}

void Display() {
    int i;
    struct Element *p;
    for (i = 0, p = head; p != NULL; i++, p = p->next)
        printf("%6d: %p %6c %p\n", i, p, p->data, p->next);
}

int main() {
    char c;
    Initialize();

    // while ((c = getchar()) != EOF) {
    // 問題２-1　文字がEOFの場合、プログラムを終了する
    while (scanf("%c", &c) !=         ) {
        switch (c) {
            case ' ': // 問題２-2　半角スペースの場合、すべてのデータをデキューして一行で出力する
                if (head == NULL)
                    printf("QUEUE empty\n");
                else {
                    printf("Input characters: ");
                    while (                ) // 取り出しの継続条件
                        printf(                  );
                    printf("\n");
                }
                break; // switch文から抜け出るbreak必要に注意！
            case '\n':  // 問題２-3　改行の場合、何もせずswitch文から抜け出る（設問なし）
                break;
            default:   // それ以外の文字の場合、エンキューし、キューを表示する
                
                Display();
                break;
        }
    }

    // 作法としては、free()する
    return 0;
}
