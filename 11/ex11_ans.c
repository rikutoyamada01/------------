/* アルゴリズムとデータ構造B
   3I ○番 氏名 提出日：
   #11 線形リスト序論
   要素数10の構造体配列 node を順に連結して線形リストを作成し，
   各ノードのアドレス，data, nextを出力する */

#include <stdio.h>
#define N 10

// 設問１：線形リストのノードを実現するための構造体を定義する
struct Element {
    int data;
    struct Element *next;
};

int main() {
    int i;
    // 設問２：ノード用の構造体配列 node（要素数 N）を宣言する
    struct Element node[N];

    // 設問３：配列 0 から 8 番目まで，次のノードに順に連結する
    // ノードの data に代入する値は i*i*i とする
    for (i = 0; i < N - 1; i++) {
        node[i].data = i * i * i;
        node[i].next = &node[i + 1];
    }

    // 設問４：末端ノード（9番目）を正しく設定する
    node[N - 1].data = (N - 1) * (N - 1) * (N - 1);
    node[N - 1].next = NULL;

    // 設問５：head を正しく設定する
    struct Element *head = &node[0];  // 線形リストの先頭

    // 設問６：先頭から各ノードの情報（ノードのアドレス，値（data），次のノードのアドレス（next））を出力する
    struct Element *p;
    printf("adress\t\tdata\tnext\n");
    for (p = head; p != NULL; p = p->next){
        printf("%p\t%d\t%p\n", p, p->data, p->next);
    }

    return 0;
}

/* 実行結果を以下に貼り付けて提出
❯ ./ex11
adress          data    next
0x7fffe207c670  0       0x7fffe207c680
0x7fffe207c680  1       0x7fffe207c690
0x7fffe207c690  8       0x7fffe207c6a0
0x7fffe207c6a0  27      0x7fffe207c6b0
0x7fffe207c6b0  64      0x7fffe207c6c0
0x7fffe207c6c0  125     0x7fffe207c6d0
0x7fffe207c6d0  216     0x7fffe207c6e0
0x7fffe207c6e0  343     0x7fffe207c6f0
0x7fffe207c6f0  512     0x7fffe207c700
0x7fffe207c700  729     (nil)
*/
