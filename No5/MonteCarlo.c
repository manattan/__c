#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void)
{
    double x, y;
    FILE *fp;

    srand((unsigned)time(NULL));

    fp = fopen("Monte.txt", "w");

    for (double N = 10.0; N < 10 * 10 * 10 * 10 * 10 * 10 * 10; N = N * 10)
    {
        double n = 0.0;
        double pi = 0;
        for (int i = 0; i < N; i++)
        {
            x = (double)rand() / (double)RAND_MAX;
            y = (double)rand() / (double)RAND_MAX;
            if (x * x + y * y <= 1.0)
            {
                n++;
                printf("円の中に入ったあ！");
            }
            else
            {
                printf("円の外やったあ");
            }
        }
        pi = 4 * n / N;
        fprintf(fp, "%f回ランダムプロットしたとき、π=%lf\n", N, pi);
    }

    fclose(fp);
    return 0;
}

// 実行結果
// 10.000000回ランダムプロットしたとき、π=1.600000
// 100.000000回ランダムプロットしたとき、π=3.120000
// 1000.000000回ランダムプロットしたとき、π=3.160000
// 10000.000000回ランダムプロットしたとき、π=3.156400
// 100000.000000回ランダムプロットしたとき、π=3.147680
// 1000000.000000回ランダムプロットしたとき、π=3.142220

// プロット数を大きくすると円周率は正確になっていく（当然）