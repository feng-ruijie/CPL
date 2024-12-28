#include<stdio.h>
#include<string.h>
#include<malloc.h>
int l1,l2,d1,d2,size;
char *interleaveString(char *s1,char *s2){
    char *s3 = malloc(size+1);
    char *s4 = s3;
    int sum = 0;
    while(1){
        for(int i=1;i<=d1;i++){
            if(size-1 == sum || *s1 == '\0') break;
            *s3 = *s1;
            s1 ++ ,s3 ++ ,sum ++;
        }
        for(int i=1;i<=d2;i++){
            if(size-1 == sum || *s2 == '\0') break;
            *s3 = *s2;
            s2 ++ ,s3 ++ ,sum ++;
        }
        if(size-1 == sum || (*s1 == '\0' && *s2 == '\0')) break;
    }
    *s3 = '\0';
    return s4;
}
int main(){
    int T;
    scanf("%d", &T);
    getchar();
    while(T--){
        char *s1=malloc(1007),*s2=malloc(1007); 
        scanf("%[^;];%[^;];%d;%d;%d\n", s1, s2, &d1, &d2, &size);
        printf("%s\n",interleaveString(s1,s2));
        free(s1),free(s2);
    }
}