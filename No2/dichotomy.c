#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define eps 1.0e-5 //収束条件

double f(double x){
    return x*x-1;
}

int main(void){
    int count; //無限ループを避ける
    double a,b,m;
    while(1){
        printf("a=");
        scanf("%lf",&a);
        printf("b=");
        scanf("%lf",&b);

        if(f(a)*f(b)<0) break;
        else printf("f(a)*f(b)<0の条件を満たしていません\n");
    };

    count = 0;

    do{
        count++;
        m=(a+b)/2;
        if(f(m)==0) break; //条件を追加
        if(f(m)*f(a)<0) b=m;
        else a=m;

        if(count==1000){
            printf("exit.\n");
            exit(1);
        };
    }while(fabs(a-b)>eps);

    printf("x=%f count=%d\n",m,count);
    return 0;
}

