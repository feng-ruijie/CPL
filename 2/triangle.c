#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a+b<c) printf("not triangle");
    else{
        if(a == b && b == c){
            printf("equilateral triangle");
        }
        else if(a*a + b*b == c*c){
            printf("right triangle");
        }
        else{
            if(a*a + b*b < c*c){
                printf("obtuse ");
            }
            if(a*a + b*b > c*c){
                printf("acute ");
            }
            if(a==b || b==c || a==c){
                printf("isosceles ");
            }
            printf("triangle");
        }
    }
    return 0;
}