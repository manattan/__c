// # include "stdafx.h"
# include "stdio.h"

void main(void) {
    double x,y;
    FILE *fp, *fpp;
    int err,err2; // errno_t が望ましい...

    err = fopen_s(&fp, "sample3_1.txt","a"); // 追加書き込み
    err2 = fopen_s(&fpp, "sample3_2.txt", "x"); // 上書き

    if (err!=0 | err2!=0) {
        printf("ファイルを読み込めませんでした"); //オープンモードがrでないため不要
    } else {
        printf("x= ");
        scanf("%lf",&x);

        printf("y= ");
        scanf("%lf",&y);

        fprintf(fp,"%f\t%f",x,y);
        fprintf(fpp,"%f\t%f",x,y);

        fclose(fp);
        fclose(fpp);
    }
}

// 最初は同じように書き込まれるが、2回目以降は異なる(モードの違い)