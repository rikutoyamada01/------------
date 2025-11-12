/* アルゴリズムとデータ構造B
   3I 50番 氏名 山田陸斗　提出日：2025年11月12日
   #11 線形リスト序論
   要素数10の構造体配列 node を順に連結して線形リストを作成し，
   各ノードのアドレス，data, nextを出力する */

#include <stdio.h>
#define N 10

// 設問１：線形リストのノードを表現するための構造体(struct Element)を定義する
struct Element {
    int data;
    struct Element* next;
};

int main() {
    int i;
    // 設問２：ノード用の構造体配列 node（要素数 N）を宣言する
    struct Element node[N];


    // 設問３：配列 0 から 8 番目まで，次のノードに順に連結する
    // i番目のノードの data に代入する値は i*i*i とする
    for (i=0; i < N - 1; i++) {
        node[i].data = i*i*i;
        node[i].next = &node[i+1];
    }


    // 設問４：末端ノード（9番目）を正しく設定する
    node[N - 1].data = (N - 1) * (N - 1) * (N - 1);
    node[N - 1].next = NULL;

    // 設問５：head を正しく設定する
    struct Element *head = &node[0];  // 線形リストの先頭


    // 設問６：先頭から各ノードの情報（ノードのアドレス，値（data），次のノードのアドレス（next））を出力する
    struct Element* p;
    printf("adress\t\tdata\tnext\n");
    for (p = head; p != NULL; p = p->next){
        printf("%p\t%d\t%p\n", p, p->data, p->next);
    }

    return 0;
}

/* 実行結果を以下に貼り付けて提出
adress		data	next
0x7ffc085ad010	0	0x7ffc085ad020
0x7ffc085ad020	1	0x7ffc085ad030
0x7ffc085ad030	8	0x7ffc085ad040
0x7ffc085ad040	27	0x7ffc085ad050
0x7ffc085ad050	64	0x7ffc085ad060
0x7ffc085ad060	125	0x7ffc085ad070
0x7ffc085ad070	216	0x7ffc085ad080
0x7ffc085ad080	343	0x7ffc085ad090
0x7ffc085ad090	512	0x7ffc085ad0a0
0x7ffc085ad0a0	729	(nil)
*/
