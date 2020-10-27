# include "stdio.h"

double f1(double v){
    return v;
}

double f2(double x){
    return -1*x;
}

int main(void){
    double x,v,dt,tmax;
    double kx[4],kv[4];
    FILE *fp;

    fp=fopen("data.txt","a");
    fprintf(fp,"t\tx\tv\n");
    printf("x=");
    scanf("%lf",&x);
    printf("v=");
    scanf("%lf",&v);
    printf("dt=");
    scanf("%lf",&dt);
    printf("tmax=");
    scanf("%lf",&tmax);

    for (double t=0.0;t<tmax;t+=dt){
        kx[0]=dt*f1(v);
        kv[0]=dt*f2(x);
        kx[1]=dt*f1(v+kv[0]/2);
        kv[1]=dt*f2(x+kx[0]/2);
        kx[2]=dt*f1(v+kv[1]/2);
        kv[2]=dt*f2(x+kx[1]/2);
        kx[3]=dt*f1(v+kv[2]);
        kv[3]=dt*f2(x+kx[2]);

        x+=(kx[0]+kx[1]*2+kx[2]*2+kx[3])/6;
        v+=(kv[0]+kv[1]*2+kv[2]*2+kv[3])/6;
        fprintf(fp,"%f\t%f\t%f\n",t,x,v);
    }
    fclose(fp);
    return 0;
}



