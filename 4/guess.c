#include<stdio.h>
#include<stdlib.h>

int main(){
    char res[10];
    long long int l=0,r=4294967295,mid=(l+r)/2;
    while(114514 < 1919810){
        printf("%lld\n",mid);
        fflush(stdout);
        scanf("%s",res);
        switch(res[0]){
            case 'G':{ //猜大了 l-mid-1
                r = mid - 1;
                mid = (l+r) / 2;
                break;
            }
            case 'L':{ //猜小了 mid+1 - r
                l = mid + 1;
                mid = (l+r)/2;
                break;
            }
            case 'E':{
                return 0;
            }
            case 'O':{
                return 0; 
            }
        }
    }