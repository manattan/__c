# include "stdio.h"

double f1(double v){
    return v;
}

double f2(double x){
    return -1*x;
}

int main(void){
    double x,v,dt,tmax;
    double k[2];
    FILE *fp;

    fp=fopen("data2.txt","a");
    fprintf(fp,"t\tx\tv\n");
    printf("x=");
    scanf("%lf",&x);
    printf("v=");
    scanf("%lf",&v);
    printf("dt=");
    scanf("%lf",&dt);
    printf("tmax=");
    scanf("%lf",&tmax);

    for(double t=0.0;t<=tmax;t+=dt){
        k[0]=dt*f1(v);
        k[1]=dt*f2(x);
        x+=k[0];
        v+=k[1];
        fprintf(fp,"%f\t%f\t%f\n",t,x,v);
    }
    
    fclose(fp);
    return 0;
}