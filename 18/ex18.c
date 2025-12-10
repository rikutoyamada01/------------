/* アルゴリズムとデータ構造B
   3I ○番 氏名 提出日：
   #18 木の静的な作成．縦型探索
   設問：縦型探索用 の PrintTree 関数を作成 */

#include <stdio.h>

// 設問１：ノード用の構造体（struct Node）の定義
struct Node {
    int data;
    
    
};
// 設問２：根を指すポインタ root の宣言，初期化
             root;
void Initialize() {  // 今のところ不要
    root =           ;
}

void PrintTree(struct Node *p) {

    if (         ) {
        // 設問３：縦型探索（三通り記述．実行時は他の二つをコメントアウト）

        // 行きがけ順

        // 通りがけ順

        // 帰りがけ順

    }
}

int main() {
    Initialize();

    // 設問４：構造体配列（要素数10）を宣言し，木を静的に作成
    // data部に値を代入し，left, right を正しく接続
    struct Node node[    ];


    // 設問５：根の設定
    root =            ;

    PrintTree(root); // 縦型探索関数呼び出し（変更の必要なし）

    return 0;
}

/* 実行結果を以下に貼り付けて提出
   行きがけ順，通りがけ順，帰りがけ順のそれぞれの出力結果を貼り付ける

*/
