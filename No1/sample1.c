# include "stdio.h"

//なぜか返り値をintにしてreturn 0 としないとwarn（main関数のデフォルト）になる、以降のファイルも同様
void main(void){
    printf("start\t"); // tab
    printf("test\n"); // 改行
    printf("end\n");
}

// 実行はvsCodeにて "gcc -o a.out ファイル名.c" としている