# include "stdio.h"
# include "stdlib.h"
# include "time.h"

int main(void){
    double x,y;
    FILE *fp;

    srand((unsigned) time(NULL));

    fp=fopen("Monte.txt","w");
    
    for (double N=10.0;N<10*10*10*10*10*10*10;N=N*10){
        double n=0.0;
        double pi=0;
        for (int i=0;i<N;i++) {
            x=(double)rand()/(double) RAND_MAX;
            y=(double)rand()/(double) RAND_MAX;
            if (x*x+y*y<=1.0){
                n++;
                printf("円の中に入ったあ！");
            } else {
                printf("円の外やったあ")
            }
        }
        pi = 4*n/N;
        fprintf(fp,"%f回ランダムプロットしたとき、π=%lf\n",N,pi);
    }

    fclose(fp);
    return 0;
}