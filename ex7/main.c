#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);
    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟檔案！\n");
        return 1;
    }

    // 初始化亂數種子
    srand((unsigned)time(NULL));

    // 取得當前時間並去除 ctime() 結尾的換行符號 '\n'
    time_t curtime;
    time(&curtime);
    char *time_str = ctime(&curtime);
    for (int i = 0; time_str[i] != '\0'; i++) {
        if (time_str[i] == '\n') {
            time_str[i] = '\0';
            break;
        }
    }

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);
        if (i <= n) {
            int num[7];
            // 產生 7 個 1~69 不重複的亂數
            for (int j = 0; j < 7; j++) {
                int temp, duplicate;
                do {
                    duplicate = 0;
                    temp = rand() % 69 + 1;
                    for (int k = 0; k < j; k++) {
                        if (num[k] == temp) {
                            duplicate = 1;
                            break;
                        }
                    }
                } while (duplicate);
                num[j] = temp;
            }

            // 將前 6 個數字由小到大排序 (氣泡排序法)
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5 - j; k++) {
                    if (num[k] > num[k + 1]) {
                        int swap = num[k];
                        num[k] = num[k + 1];
                        num[k + 1] = swap;
                    }
                }
            }

            // 輸出 7 個號碼，個位數前方補 0 (%02d)
            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d%s", num[j], (j == 6) ? "" : " ");
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "-- -- -- -- -- -- --\n");
        }
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    return 0;
}
