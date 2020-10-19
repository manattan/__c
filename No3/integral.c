# include "stdio.h"
# include "math.h"

double f(double x) {
    return sin(x);
}

int main(void){
    double a,b;
    double S,h,xi,xn;
    FILE *fp;

    printf("sinxの積分を行います.積分区間[a,b]を入力してください.\n");
    printf("a=");
    scanf("%lf",&a);
    printf("b=");
    scanf("%lf",&b);

    fp=fopen("data.txt","a");

    fprintf(fp,"sinxの積分.\n積分区間は[%lf, %lf]\n",a,b);
    for(int N=10;N<100000;N=N*10){
        h=fabs(b-a)/N; //積分区間を1000等分する
        S=0.0;
        for(int i=0;i<N;i++){
            xi=a+i*h;
            xn=a+(i+1)*h;

            S+=h*(f(xi)+f(xn))/2;
        }
        fprintf(fp,"積分区間を%d等分した時の面積Sは %lf\n",N,S);
        printf("積分区間を%d等分した時の面積Sは %lf\n",N,S);
    }

    fclose(fp);

    return 0;
}