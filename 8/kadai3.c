#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
#include <string.h>

// スタックと付随するアルゴリズムはex07.cで実装したものを用いても良い
#define MAX 5

int stk[MAX];
int ptr;

int Push(int x) {
    // 問題１-1　演習07の復習
    if (ptr < MAX      )
        stk[++ptr] = x;
    else
        return -1;

    return 0;
}

int Pop() {
    if (ptr >= 0)
        // 問題１-2　演習07の復習
        return stk[   ptr   ];
    else
        return -1;
}

void Initialize() {
    // 問題１-3　演習07の復習
    ptr =         ;
}

void Display(){
    printf("\n");
    int i;
    for (i = MAX - 1; i >= 0; i--) {
        if (i == ptr)
            printf("PTR->");
        else
            printf("     ");
        printf("%6d:%6d\n", i, stk[i]);
    }
    printf("\n");
}

int main() {

    char str[10];
    FILE *fp;
    fp = fopen("input_kadai3.txt", "r");

    if (fp == NULL){
        printf("ファイルが開けませんでした\n");
        exit(1);
    }

    Initialize();

    while(fscanf(fp, "%s", str) != EOF){ // ファイルの読み込み
    // while((c = fgetc(fp)) != EOF){ // ファイルの読み込み
        if (strcmp(str, "end") == 0) {  // 式の終わり
            printf("式の終わりまで走査しました。");
            // 問題２　スタックから結果を取り出す
            int result =           ;
            // printf("Pop number %d\n", result);
            printf("計算結果は%dです\n\n", result);
        } else if (strcmp(str, "+") == 0) {
            // printf("%s\n", str);
            // 問題３　スタックから値を２個(one, two)取り出す
            int one =             ;
            int two =             ;
            printf("%dをポップしました\n", one);
            printf("%dをポップしました\n", two);
            // 問題４-1　正しく計算して、スタックに値を入れる　※残りの演算も
            result =        (one     two);
            printf("%d + %dを計算します\n", one, two);
            printf("計算結果の%dをプッシュします\n", one + two);
            Display();
        } else if (strcmp(str, "-") == 0) {
            // printf("%s\n", str);
            int one = Pop();
            int two = Pop();
            printf("%dをポップしました\n", one);
            printf("%dをポップしました\n", two);
            // 問題４-2　正しく計算して、スタックに値を入れる
            result =                  ;
            printf("%d - %dを計算します\n", two, one);
            printf("計算結果の%dをプッシュします\n", two - one);
            Display();
        } else if (strcmp(str, "*") == 0) {
            // printf("%s\n", str);
            int one = Pop();
            int two = Pop();
            printf("%dをポップしました\n", one);
            printf("%dをポップしました\n", two);
            // 問題４-3　正しく計算して、スタックに値を入れる
            result =        (one     two);
            printf("%d * %dを計算します\n", one, two);
            printf("計算結果の%dをプッシュします\n", one * two);
            Display();
        } else if (strcmp(str, "/") == 0) {
            // printf("%s\n", str);
            int one = Pop();
            int two = Pop();
            printf("%dをポップしました\n", one);
            printf("%dをポップしました\n", two);
            // 問題４-4　正しく計算して、スタックに値を入れる
            result =                  ;
            printf("%d / %dを計算します\n", two, one);
            printf("計算結果の%dをプッシュします\n", two / one);
            Display();
        } else {  // 数字
            // 問題５-1　string.hの関数を用いて、文字列を数値に変換する
            int num =          (str);
            printf("%dをプッシュします\n", num);
            // 問題５-2　値(num)をスタックに入れる。
            result =           (num);
            Display();
        }
    }
    fclose(fp);

    return 0;
}
