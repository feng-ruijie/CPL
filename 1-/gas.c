#include<stdio.h>
#include<string.h>

int main(){
    const double R = 8.314;
    double P,V,n,T,L;
    scanf("%lf%lf%lf",&P,&L,&V);
    V = L * L * L;
    n = (P*V)/(R*T);
    printf("%.5le",n);
}