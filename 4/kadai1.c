// アルゴリズムとデータ構造 課題1
// 提出者：3I 山田 陸斗

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 在庫データの構造体定義
struct stock {
    char title[20];
    char author[20];
    int year;
    int stock;
    int price;
};



// バブルソート用の関数
void bsort(struct stock *a, int n)
{
    int i, j;
    struct stock tmp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j].stock * a[j].price < a[j+1].stock * a[j+1].price) {
                tmp      = a[j];
                a[j]     = a[j + 1];
                a[j + 1] = tmp;
            }
}

int main()
{
    int n, i;
    printf("要素数を入力: ");
    scanf("%d", &n);  // 構造体配列の要素数
    
    struct stock library_tmp[6] = {
        {"Programming", "Dennis", 1978, 10, 2500},
        {"Algorithm", "Thomas", 2009, 15, 6800},
        {"Language", "Brian", 2023, 2, 9500},
        {"Visualization", "Donald", 1968, 8, 5500},
        {"Mathematics", "Robert", 2008, 5, 4800},
        {"Research", "Dennis", 1998, 12, 3700}
    };

    // 配列の動的生成
    struct stock *stock_p;
    stock_p = malloc(sizeof(struct stock) * n);

    // エラー処理
    if (stock_p == NULL) {
        printf("領域を確保できませんでした\n");
        exit(1);
    }

    /*
    for (i = 0; i < n; i++) {
        stock_p[i] = library_tmp[i];
        printf("Title: %s, Author: %s, Year: %d, Stock: %d, Price: %d\n", stock_p[i].title, stock_p[i].author, stock_p[i].year, stock_p[i].stock, stock_p[i].price);
    }
    */

    
    for(i = 0; i < n; i++){
        printf("Title:\n");
        scanf("%s", stock_p[i].title);
        printf("Author:\n");
        scanf("%s", stock_p[i].author);
        printf("Year:\n");
        scanf("%d", &stock_p[i].year);
        printf("Stock:\n");
        scanf("%d", &stock_p[i].stock);
        printf("Price:\n");
        scanf("%d", &stock_p[i].price);
    }

    int total = 0;
    printf("本のタイトル\t著者\t発行年\t在庫\t値段\n");
    for(i = 0; i < n; i++) {
        // 1980年より前である在庫のデータを出力
        if( stock_p[i].year < 1980 ){
            printf("%s\t%s\t%d\t%d\t%d\n", stock_p[i].title, stock_p[i].author, stock_p[i].year, stock_p[i].stock, stock_p[i].price);
        }
        // 著者がDennisである在庫の合計をカウントし、ループ後に出力
        if( strcmp(stock_p[i].author, "Dennis") == 0 ){
            total += stock_p[i].stock;
        }
    }
    printf("著者がDennisである在庫の合計数：%d冊\n", total);

    // 在庫数×金額の最大値，最小値を求める
    bsort(stock_p, n);

    // ここまでにソートが完了しているとして、0番目とn - 1番目を出力
    printf("在庫数×金額の値が最大となるデータ：");
    printf("%s,%s,%d,%d,%d\n", stock_p[0].title, stock_p[0].author, stock_p[0].year, stock_p[0].stock, stock_p[0].price);
    printf("在庫数×金額の値が最小となるデータ：");
    printf("%s,%s,%d,%d,%d\n", stock_p[n - 1].title, stock_p[n - 1].author, stock_p[n - 1].year, stock_p[n - 1].stock, stock_p[n - 1].price);

    // 領域の解放
    free(stock_p);
    printf("領域を解放しました\n");

    return 0;
}
