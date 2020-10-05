# include "stdio.h"

void main(void){
    double x; // 実数xを定義
    printf("x=");
    scanf("%lf",&x); // scanf_sとする必要はない

    printf("x^2 = %10.5f\n", x*x); // 文字幅10,小数点以下5桁で実数表示
    printf("x^2 = %d\n", (int)(x*x)); // intで出力
}