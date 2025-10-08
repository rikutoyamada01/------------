#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // POSIX: Windows環境では_sleep()に変更する

int main() {
    int iteration = 0;
    size_t alloc_size = 1024 * 1024;  // 1MBのメモリを毎回確保
    while (1) {
        void *leak = malloc(alloc_size);  // メモリを確保（freeしない）

        if (leak == NULL) {
            printf("メモリの確保に失敗しました。\n");
            return 1;
        }

        // 確保したメモリの一部に書き込む（メモリの確保が本当に行われていることを確認するため）
        for (int i = 0; i < alloc_size; i++) {
            ((char*)leak)[i] = 0;
        }

        iteration++;
        printf("Iteration %d: %ld MB allocated\n", iteration, (long)iteration);

        // 1秒間待機 (POSIX環境ではsleep、WindowsではSleep(1000)に変更)
        sleep(1);
    }

    // printf("Size of int: %zu bytes\n", sizeof(int));
    // printf("Size of char: %zu bytes\n", sizeof(char));
    // printf("Size of float: %zu bytes\n", sizeof(float));
    // printf("Size of double: %zu bytes\n", sizeof(double));
    // printf("Size of long int: %zu bytes\n", sizeof(long int));

    return 0;
}
