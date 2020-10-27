#include "stdio.h"
#include "math.h"

#define n 3
#define max 1000
#define eps 1.0e-6

int main(void){
    int i,j,k;
    double xold[n]={1.0,1.0,1.0};
    double xnew[n],err;

    double a[n][n];
    for (int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("a%d%dの数字を入力してください:",i,j);
            scanf("%lf",&a[i][j]);
        }
    }

    double b[n];
    for(int j=0;j<n;j++){
        printf("b%dの数字を入力してください:",j);
        scanf("%lf",&b[j]);
    }

    for (k=0;k<max;k++) {
        err=0.0;
        for (i=0;i<n;i++) {
            xnew[i]=b[i];
            for (j=0;j<n;j++){
                if(j!=i){
                    xnew[i]-=a[i][j]*xold[j];
                }
                xnew[i]/=a[i][i];
            }
        }
        for (i=0;i<n;i++) {
            err+=fabs(xold[i]-xnew[i]);
            xold[i]=xnew[i];
        }
        if (err<eps) {
            break;
        }
    }
    for (i=0;i<n;i++) {
        printf("xnew[%d] = %e\n",i,xnew[i]);
    }
    printf("k = %d\n",k);
    return 0;
}