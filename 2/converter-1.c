#include<stdio.h>

static char *ones[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static char *tens[] = {
  "0", "1", "twenty", "thirty", "forty", 
  "fifty", "sixty", "seventy", "eighty", "ninety"};
int main(){ 
    int n;
    scanf("%d",&n);
    if(n <= 19){
        printf("%s",ones[n]);
    }
    else{
        if(n <= 99){
            if(n % 10 == 0){
                printf("%s",tens[n/10]);
            }
            else{
                printf("%s-%s",tens[n/10],ones[n%10]);
            }
        }
        else{
            if(n%100 == 0){
                printf("%s hundred",ones[n/100]);
            }
            else{
                printf("%s hundred and ",ones[n/100]);
                int m = n % 100;
                if(m <= 19){
                    printf("%s",ones[m]);
                }
                else{
                    if(m % 10 == 0){
                        printf("%s",tens[m/10]);
                    }
                    else{
                        printf("%s-%s",tens[m/10],ones[m%10]);
                    }
                }
            }
        }
    }
}