#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<string.h>
int strlen1(const char *s){ 
    int len = 0;
    while(s[++len] != '\0'){
    }
    return 0;
}

size_t strlen2(const char *s){
    const char *sc;
    for(sc = s; *sc != '\0'; ++sc){

    }
    return sc - s;
}

size_t strlen3(const char *s,size_t max){
    size_t count = 0;
    while(max && *s!='\0'){
        count ++;
        s ++; 
        max --;
    }
}

void strcpy1(char *dest,const char *src){
    int i = 0;
    while((dest[i] = src[i]) != '\0'){
        i++;
    }
}
void strcpy2(char *dest,const char *src){
    int i = 0; 
    while((*(dest + i) = *(src + i)) != '\0'){

    }
}
void strcpy3(char *dest,const char *src){
    while((*dest = *src) != '\0'){
        dest ++ , src ++; 
    }
    
}
void strcpy4(char *dest,const char *src){

    while((*dest++ = *src++)!= '\0'){

    }
    //printf("%s",src);
}
int strcmp1(const char *s1,const char *s2){
    while(*s1 == *s2 && (*s1 != '\0') && (*s2 != '\0')){
        s1 ++ , s2 ++; 
    }
    return *s1 - *s2;
}
int main(){
    //char str[] = "cpy";
    //str[0] = 'n';
   // printf("%s",str);
    char *s1 = "hello" , *s2 ="helloafa";
    printf("%d\n",strcmp1(s1,s2));
    char *s = "helloworld";
    //*s = 'a'; //will take seg fault

    const char *src = "Helloworld!";
    char *dest =  malloc(strlen(src)+1);

    strcpy4(dest,src);
    printf("%c",*dest); //success

    size_t s3 = strlen3(s,99);
   // printf("%c",*s); //s 所指向的位置没有发生改变
    return 0;
}
