/* アルゴリズムとデータ構造B
   3I ○番 氏名 提出日：
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
void Initialize() {  // 今のところ不要
    root = NULL;
}

void PrintTree(struct Node *p) {
    // 設問３：縦型探索（三通り記述．実行時は他の二つをコメントアウト）
    if (p != NULL) {
        // 行きがけ順
        // printf("%d ", p->data);
        // PrintTree(p->left);
        // PrintTree(p->right);

        // 通りがけ順
        // PrintTree(p->left);
        // printf("%d ", p->data);
        // PrintTree(p->right);

        // 帰りがけ順
        PrintTree(p->left);
        PrintTree(p->right);
        printf("%d ", p->data);
    }
}

int main(){
    Initialize();

    // 設問４：構造体配列（要素数10）を宣言し，木を静的に作成
    // data部に値を代入し，left, right を正しく接続
    struct Node node[10];
    node[0].data = 25;
    node[0].left = &node[1];
    node[0].right = &node[3];

    node[1].data = 14;
    node[1].left = &node[2];
    node[1].right = NULL;

    node[2].data = 8;
    node[2].left = NULL;
    node[2].right = NULL;

    node[3].data = 46;
    node[3].left = &node[4];
    node[3].right = &node[5];

    node[4].data = 28;
    node[4].left = NULL;
    node[4].right = NULL;

    node[5].data = 52;
    node[5].left = NULL;
    node[5].right = &node[6];

    node[6].data = 79;
    node[6].left = &node[7];
    node[6].right = &node[8];

    node[7].data = 74;
    node[7].left = &node[9];
    node[7].right = NULL;

    node[8].data = 84;
    node[8].left = NULL;
    node[8].right = NULL;

    node[9].data = 68;
    node[9].left = NULL;
    node[9].right = NULL;

    // 設問５：根の設定
    root = &node[0];

    printf("帰りがけ順\n");
    PrintTree(root); // 縦型探索関数呼び出し（変更の必要なし）
    printf("\n");

    return 0;
}

/* 実行結果を以下に貼り付けて提出
   行きがけ順，通りがけ順，帰りがけ順のそれぞれの出力結果を貼り付ける

行きがけ順
25
14
8
46
28
52
79
74
68
84

通りがけ順
8
14
25
28
46
52
68
74
79
84

帰りがけ順
8
14
28
68
74
84
79
52
46
25

*/
