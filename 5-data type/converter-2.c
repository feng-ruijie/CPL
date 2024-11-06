#include<stdio.h>


static char *ones[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static char *tens[] = {
  "0", "1", "twenty", "thirty", "forty", 
  "fifty", "sixty", "seventy", "eighty", "ninety"};
void print_hundred(int x){ //x < 1000
    if(x < 20){
        printf("%s",ones[x]);
    }
    else{
        if(x <= 99){
            if(x % 10 == 0){
                printf("%s",tens[x/10]);
            }
            else{
                printf("%s-%s",tens[x/10],ones[x%10]);
            }
        }
        else{
            if(x % 100 == 0){
                printf("%s hundred",ones[x/100]);
            }
            else{
                printf("%s hundred and ",ones[x/100]);
                int m = x % 100;
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
const int bi = 1000*1000*1000,mi = 1000*1000,th = 1000;
int main(){
    int n;
    scanf("%d",&n);
    if(n == -2147483648){
        printf("minus two billion one hundred and forty-seven million four hundred and eighty-three thousand six hundred and forty-eight");
        return 0; 
    }
    if(n < 0){
        n = -n;
        printf("minus ");
    }
    if(n >= bi){
        print_hundred(n/bi);
        printf(" billion");
        n %= bi;
        if(n >= mi){
            printf(" ");
            print_hundred(n/mi);
            printf(" million");
            n %= mi; 
        }
        if(n >= th){
            printf(" ");
            print_hundred(n/th);
            printf(" thousand");
            n %= th;
        }
        if(n > 0){
            printf(" ");
            print_hundred(n);
        }
    }
    else if(n >= mi){
        print_hundred(n/mi);
        printf(" million");
        n %= mi; 
        if(n >= th){
            printf(" ");
            print_hundred(n/th);
            printf(" thousand");
            n %= th;
        }
        if(n > 0){
            printf(" ");
            print_hundred(n);
        }
    }
    else if(n >= th){
        print_hundred(n/th);
        printf(" thousand");
        n %= th;
        if(n > 0){
            printf(" ");
            print_hundred(n);
        }
    }
    else{
        print_hundred(n);
    }
    return 0; 
}