# include "stdio.h"
# include "math.h"

//演習問題1-2 連立方程式の解を出力するプログラム
// ガウス法でやりました(コメントでは一番上の行を0行、左の列を0列としている)
int main(void) {
    int n;
    printf("連立方程式の解を求めるプログラムです。\n次数を整数で入力してください");
    scanf("%d",&n);
    double arr[n][n+1];
    for (int i = 0;i<n;i++){
        for(int j=0;j<n+1;j++){
            printf("%d行%d列目の数字を入力してください:",i,j);
            scanf("%lf",&arr[i][j]);
        }
    }

    for(int i=0;i<n;i++){ //行を変える、n周
        printf("次のフェーズi=%d\n",i);
        printf("割る数は%lf\n",arr[i][i]);
        double c;
        if(arr[i][i] == 0){
            printf("解が存在しません\n");
            return 0;
        } else if (arr[i][i]<0) {
            printf("割る数が負ですね\n");
            c = -1* arr[i][i];
            for(int k=0;k<n+1;k++){ // i行の値をi行i列目の値で全部割る（本当は全部でなくて良い）,n+1周
                arr[i][k] /= c;
                arr[i][k] *= -1;
            }
        } else if(arr[i][i]>0){
            printf("割る数が正ですね\n");
            c = arr[i][i];
            printf("cは%lf\n",c);
            for(int k=0;k<n+1;k++){// i行の値をi行i列目の値で全部割る（本当は全部でなくて良い）,n+1周
                if(arr[i][k]!=0){
                    printf("%.3f\n",arr[i][k]/c);
                    arr[i][k]/=c;
                }
            }
        }
        // printf("割る数は%d\n",c);
        // printf("行を割っていきます\n");
        // printf("割り終わりました\n");
        printf("行列は\n");
        for(int m=0;m<n;m++){
            for(int o=0;o<n+1;o++){
                printf("%lf\t",arr[m][o]);
            }
            printf("\n");
        }
        printf("です\n");
        printf("次のフェーズi=%d\n",i);
        for(int j=0;j<n;j++){
            double x=arr[j][i];
            for(int l=0;l<n+1;l++){
                if(i!=j){
                    printf("関与する数字は%lf\n",x);
                    arr[j][l] -= (arr[i][l]*x);
                    printf("行列は\n");
                    for(int m=0;m<n;m++){
                        for(int o=0;o<n+1;o++){
                            printf("%lf\t",arr[m][o]);
                        }
                        printf("\n");
                    }
                    printf("です\n");
                }
            }
        }
        // for(int v=0;v<n+1;v++){
        //     printf("%lf\n",arr[i][v]);
        // }    
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                if(arr[i][j]==1){
                    continue;
                } else if(arr[i][j]!=1) {
                    printf("\n1になってない");
                }
            } else {
                if(arr[i][j]==0){
                    continue;
                } else if(arr[i][j]!=0){
                    printf("\n0になっていない");
                }
            }
        }
        printf("解の1つは%lfです",arr[i][n]);
    }
}