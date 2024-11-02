#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    double p,q,a=1.0,b=1.0;
    scanf("%lf %lf",&p,&q);
    double mid = (q/2.0)*(q/2.0) + (p/3.0)*(p/3.0)*(p/3.0);
    double x1,x1a = -q/2.0+sqrt(mid) ,x2a = -q/2.0-sqrt(mid);
    if(x1a < 0) a = -1.0 , x1a = -x1a;
    if(x2a < 0) b = -1.0 , x2a = -x2a;
    
    x1 = a * pow(x1a,1.0/3.0) + b * pow(x2a,1.0/3.0);
    printf("%.3lf",x1);
}