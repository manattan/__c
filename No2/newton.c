#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define maxc 1000 //上限ループ回数をここで定義することにした
#define eps 1.0e-5

double f(double x){
    return x*x-2;
}

double df(double x){
    return 2*x;
}

int main(void){
    int count =0;
    double a,an;

    printf("a=");
    scanf("%lf",&a);

    while(1){
        count++;
        if(df(a)==0){
            printf("error.\n");
            exit(1);
        }

        an=a-f(a)/df(a);
        if(fabs(an-a)<eps) break;
        a=an;
        if(count==maxc){
            printf("error.\n");
            exit(1);
        }
    }

    printf("xs=%f count=%d\n",an,count);
    return 0;
}