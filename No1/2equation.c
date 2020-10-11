# include "stdio.h"
# include "math.h"

int main(void) {
    double a,b,c;
    printf("a= ");
    scanf("%lf",&a);
    printf("b= ");
    scanf("%lf",&b);
    printf("c= ");
    scanf("%lf",&c);

    if( b*b-4*a*c < 0){
        printf("実数解が存在しません。\n");
        return 0
    } else {
        double x1,x2;
        x1 =(-b+sqrt(b*b-4*a*c))/(2*a);
        x2 =(-b-sqrt(b*b-4*a*c))/(2*a);
        if(x1 == x2) {
            printf("x= %10.5f\n",x1);
        } else {
            printf("x= %10.5f, %10.5f\n",x1,x2);
        }
    }

}