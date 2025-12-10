/* アルゴリズムとデータ構造B
   3I 50番 氏名 山田陸斗 提出日：2025年12月10日
   #18 木の静的な作成．縦型探索
   設問：縦型探索用 の PrintTree 関数を作成 */

#include <stdio.h>

// 設問１：ノード用の構造体（struct Node）の定義
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
// 設問２：根を指すポインタ root の宣言，初期化
struct Node *root;

void PrintTree(struct Node *p) {

    if (p != NULL) {
        // 設問３：縦型探索（三通り記述．実行時は他の二つをコメントアウト）

        // 行きがけ順
        /*
        printf("%d", p->data);
        printf("\n");

        PrintTree(p->left);
        PrintTree(p->right);
        */

        // 通りがけ順
        /*
        PrintTree(p->left);

        printf("%d", p->data);
        printf("\n");

        PrintTree(p->right);
        */

        // 帰りがけ順
        
        PrintTree(p->left);
        PrintTree(p->right);

        printf("%d", p->data);
        printf("\n");

    }
}

int main() {
    // 設問４：構造体配列（要素数10）を宣言し，木を静的に作成
    // data部に値を代入し，left, right を正しく接続
    struct Node node[10];
    for (int i = 0; i < 10; i++) {
        node[i].data = i*i;
    }

    node[0].left = &node[1];
    node[1].left = &node[3];
    node[3].left = &node[7];
    node[7].left = NULL;
    node[7].right = NULL;
    node[3].right = NULL;
    node[1].right = &node[4];
    node[4].left = &node[8];
    node[8].left = NULL;
    node[8].right = NULL;
    node[4].right = &node[9];
    node[9].left = NULL;
    node[9].right = NULL;
    node[0].right = &node[2];
    node[2].left = &node[5];
    node[5].left = &node[6];
    node[6].left = NULL;
    node[6].right = NULL;
    node[5].right = NULL;
    node[2].right = NULL;



    // 設問５：根の設定
    root = &node[0];

    PrintTree(root); // 縦型探索関数呼び出し（変更の必要なし）

    return 0;
}

/* 実行結果を以下に貼り付けて提出
   行きがけ順，通りがけ順，帰りがけ順のそれぞれの出力結果を貼り付ける
行きがけ順
0
1
9
49
16
64
81
4
25
36

通りかけ順
49
9
1
64
16
81
0
36
25
4

帰りがけ順
49
9
64
81
16
1
36
25
4
0
*/
