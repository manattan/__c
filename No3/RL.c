# include "stdio.h"

double f(double i){
    return (10-2*i)/0.5; //E=10, R=2, L=0.5
}

int main(void){
    double i=0,dt,tmax=10;
    double r;
    FILE *fp;

    fp=fopen("data3.txt","a");
    fprintf(fp,"t\ti\n");
    printf("電流の時間変化を示します。\nt=0の時、i=0とします。\nまた、E=10,R=2,L=0.5とします。\n刻み幅はいくらにしますか?");
    scanf("%lf",&dt);

    for(double t=0.0;t<tmax;t+=dt){
        i+=dt*f(i);
        fprintf(fp,"%lf\t%lf\n",t,i);
    }
    fclose(fp);

    return 0;

}