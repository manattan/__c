# include "stdio.h"

double f(double i){
    return (10-2*i)/0.5; //E=10, R=2, L=0.5
}

int main(void){
    double i=0,dt,tmax=10;
    double r[4];
    FILE *fp;

    fp=fopen("dataRL.txt","a");
    fprintf(fp,"t\ti\n");
    printf("電流の時間変化を示します。\nt=0の時、i=0とします。\nまた、E=10,R=2,L=0.5とします。\n刻み幅はいくらにしますか?");
    scanf("%lf",&dt);

    for(double t=0.0;t<tmax;t+=dt){
        r[0]=dt*f(i);
        r[1]=dt*f(i+r[0]/2);
        r[2]=dt*f(i+r[1]/2);
        r[3]=dt*f(i+r[3]);
        i+=(r[0]+r[1]*2+r[2]*2+r[3])/6;
        fprintf(fp,"%lf\t%lf\n",t,i);
    }
    fclose(fp);

    return 0;

}