//  課題2　参考ファイル　※このファイルを利用する必要はありません

#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>

// 隣接する生きているセルの数をカウントする関数
// int count_neighbors(int **life, int m, int n, int row, int col) {
//     int count = 0;
//     for (int i = row - 1; i <= row + 1; i++) {
//         for (int j = col - 1; j <= col + 1; j++) {
//             // 盤面の範囲外と自分自身はカウントしない
//             if (i < 0 || i >= m || j < 0 || j >= n || (i == row && j == col)) {
//                 continue;
//             }
//             if (life[i][j] == 1) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// 次の世代の盤面を計算する関数
void update_life(int **life, int m, int n) {
    // 問題１　二次元配列をmalloc()関数で割り当てる　※以下に同等の記述（作成済み）あり
    int      new_life;
    new_life = malloc(sizeof(        ) * m);
    for (int i = 0; i < m; i++)
        new_life[     ] = malloc(sizeof(        ) * n);


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // int neighbors = count_neighbors(life, m, n, i, j);

            int neighbors = 0;
            for (int k = i-1; k <= i+1; k++) {
                for (int l = j-1; l <= j+1; l++) {
                    if (k < 0 || l < 0 || k >= m || l >= n || (k == i && l == j)) {
                        continue;
                    }

                    if (life[k][l] == 1) {
                        neighbors++;
                    }
                }
            }

            if (life[i][j] == 1) {
                // 生きているセル
                if (neighbors == 2 || neighbors == 3) {
                    new_life[i][j] = 1; // 生き続ける
                } else {
                    new_life[i][j] = 0; // 死ぬ
                }
            } else {
                // 死んでいるセル
                if (neighbors == 3) {
                    new_life[i][j] = 1; // 生き返る
                } else {
                    new_life[i][j] = 0; // 死んだまま
                }
            }
        }
    }

    // 盤面を更新
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            life[i][j] = new_life[i][j];
        }
    }


    // 問題１つづき　正しくfree()する
    // 新しい盤面のメモリを解放
    for (int i = 0; i < m; i++)
        free(           );
    free(        );
}

void print_life(int **life, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf(" ");
        for (int j = 0; j < m; j++) {
            if (life[i][j] == 1) {
                printf("■ ");
            } else {
                printf("□ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}    

int main() {
    int second = 300000;

    // 盤面のサイズ
    int n, m;
    // 盤面を表現する二次元配列
    int **life;

    // 行数と列数を入力
    printf("行数を入力してください: ");
    scanf("%d", &m);
    printf("列数を入力してください: ");
    scanf("%d", &n);

    // 世代数を入力
    // int count;
    // printf("世代数を入力してください: ");
    // scanf("%d", &count);

    // 盤面を動的に確保

    life = malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        life[i] = malloc(sizeof(int) * n);
    }

    // 問題２　テキストファイルinput_kadai2.txtからlifeに値を読み込む　fclose()も忘れずに
    // 盤面を初期化
    FILE *fp;
    fp =                                ;
    if (fp == NULL) {
        printf("ファイルを開けません\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &life[i][j]);   // fscanf()利用に修正
        }
    }
    

    // system("clear");

    // 初期状態を表示
    printf("　初期状態:\n");
    print_life(life, m, n);
    // usleep(second);

    // 問題４　世代数countの利用（入力、ループのカウント）
    // 世代数を入力
    int count;
    printf("世代数を入力してください: ");
    scanf("%d", &          );
    // system("clear");

    // ライフゲームを実行
    int **new_life;
    new_life = malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        new_life[i] = malloc(sizeof(int) * n);
    }

    for (int i = 0; i <         ; i++) {
        printf("　%d 世代目:\n", i + 1);
        // update_life(life, m, n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // int neighbors = count_neighbors(life, m, n, i, j);

                // 問題３-1　隣接するセルの状態の確認
                int neighbors = 0;
                for (int k = i-1; k <= i+1; k++) {
                    for (int l = j-1; l <= j+1; l++) {
                        if (k < 0 || l < 0 || k >= m || l >= n || (k == i && l == j)) {
                           // continue;
                        } else {

                            
                            
                            

                        }
                    }
                }

                // 問題３-2　セルの状態を更新する条件
                if (life[i][j] == 1) {
                    // 生きているセル
                    if (                           ) {
                        new_life[i][j] = 1; // 生き続ける
                    } else {
                        new_life[i][j] = 0; // 死ぬ
                    }
                } else {
                    // 死んでいるセル
                    if (                           ) {
                        new_life[i][j] = 1; // 生き返る
                    } else {
                        new_life[i][j] = 0; // 死んだまま
                    }
                }
            }
        }

        // 盤面を更新
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                life[i][j] = new_life[i][j];
            }
        }

        print_life(life, m, n);
        // usleep(second);
        // system("clear");
    }

    // 盤面のメモリを解放する関数
    for (int i = 0; i < m; i++) {
        free(life[i]);
    }
    free(life);
    // 新しい盤面のメモリを解放
    for (int i = 0; i < m; i++) {
        free(new_life[i]);
    }
    free(new_life);


    return 0;
}
