#include <stdio.h>
#include <math.h>
int main() {
    double pi1,pi2; 
    double N1 = pow(5280,3),N2=236674.0+30303.0*sqrt(61);
    pi1 = log(N1 * pow(N2,3) + 744.0)/sqrt(427);
    pi2 = 6*atan(1.0/8.0)+2*atan(1.0/57.0)+atan(1.0/239.0);
    printf("%.15lf\n%.15lf",pi1,4.0*pi2);
}