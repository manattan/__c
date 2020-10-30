#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define n 3
#define max 1000
#define eps 1.0e-6

//aを対角成分とする
int isOk(double a,double b,double c){
    if(fabs(a)>fabs(b)+fabs(c)){
        return 1; //対角優位である 
    }

    return 0;
}

int main(void){
    double b[n]={3.0,4.0,1.0};

    double k[4] = {-3.0,-1.0,10,30};

    int res[4] = {0,0,0,0};

    for(int a11=0;a11<4;a11++){
        for(int a12=0;a12<4;a12++){
            for(int a13=0;a13<4;a13++){
                for(int a21=0;a21<4;a21++){
                    for(int a22=0;a22<4;a22++){
                        for(int a23=0;a23<4;a23++){
                            for(int a31=0;a31<4;a31++){
                                for(int a32=0;a32<4;a32++){
                                    for(int a33=0;a33<4;a33++){
                                        int a[3][3]={{k[a11],k[a12],k[a13]},{k[a21],k[a22],k[a23]},{k[a31],k[a32],k[a33]}};
                                        int is = 0;
                                        int isExisted=0;
                                        double xold[n]={1.0,1.0,1.0};
                                        double xnew[n],err;
                                        for(int t=0;t<3;t++){
                                            for(int u=0;u<3;u++){
                                                printf("%3d",a[t][u]);
                                            }
                                        }
                                        printf("\n");
                                        if(isOk(k[a11],k[a12],k[a13]) && isOk(k[a22],k[a21],k[a23]) && isOk(k[a33],k[a31],k[a32])){ // 全ての行で体格優位だったら、、
                                            is = 1;
                                        }
                                        for (int g=0;g<max;g++){
                                            err=0.0;
                                            for(int i=0;i<n;i++){
                                                xnew[i]=b[i];
                                                for(int j=0;j<n;j++){
                                                    if(j!=i){
                                                        xnew[i]-=a[i][j]*xold[j];
                                                    }
                                                }
                                                xnew[i]/=a[i][i];
                                            }

                                            for(int i=0;i<n;i++){
                                                err+=fabs(xold[i]-xnew[i]);
                                                xold[i]=xnew[i];
                                            }
                                            if (err<eps) {
                                                isExisted = 1;
                                            }
                                        }
                                        if(is == 1 && isExisted==1){
                                            res[0]++;
                                            printf("対角優位で、解が存在する\n");
                                        } else if (is == 1 && isExisted ==0){
                                            res[1]++;
                                            printf("対角優位だけど、解は存在しない\n");
                                        } else if (is == 0 && isExisted ==1){
                                            res[2]++;
                                            printf("対角優位じゃないけど、解は存在する\n");
                                        } else if (is==0 && isExisted==0){
                                            res[3]++;
                                            printf("対角優位じゃないし、解は存在しない\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("-----最終結果-----\n");
    printf("対角優位で、解が存在するのは%d個\n",res[0]);
    printf("対角優位で、解が存在しないのは%d個\n",res[1]);
    printf("対角優位じゃなくて、解が存在するのは%d個\n",res[2]);
    printf("対角優位じゃなくて、解が存在しないのは%d個\n",res[3]);
    return 0;
}