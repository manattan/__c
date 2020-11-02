# include "stdio.h"

# define nx 20
# define nt 200

int main(void){
    double T[nx][nt];
    double ti,a;
    FILE *fp;

    fp=fopen("data.txt","w");

    printf("次の値を入力してください.\n");
    printf("ti= ");
    scanf("%lf",&ti);
    printf("kdt/(dx)^2= ");
    scanf("%lf",&a);

    for (int i=0;i<nx;i++) {
        T[i][0] = ti;
    }
    for (int j=0;j<nt;j++) {
        T[0][j] = T[nx-1][j] = 0;
    }
    for (int j=0;j<(nt-1);j++) {
        for (int i=1;i<(nx-1);i++){
            T[i][j+1] = T[i][j] + a * (T[i+1][j] + T[i-1][j] - 2*T[i][j]);
        }
    }
    for (int i=0;i<nx;i++) {
        for (int j=0;j<nt;j++) {
            fprintf(fp,"%d\t%d\t%f\n",i,j,T[i][j]);
        }
    }

    fclose(fp);
    return 0;
}