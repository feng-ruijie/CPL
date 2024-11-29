#include<stdio.h>
#include<string.h>

void print(char *s[],int len){
    for(int i=0;i<len;i++){
        printf("%s\n",s[i]);
    }
}
void swap(char **left,char **right){ //解引用一次还是指针
    char *temp = *left;
    *left = *right;
    *right = temp;
}/*char * const *left：表示 left 指向的指针是常量，不能修改 left 指向的地址。
char const **left：表示 left 指向的字符是常量，不能修改 left 指向的字符。*/
int GetMinindex(char *arr[0],int begin,int end){
    char *min = arr[begin];
    int index = begin;
    for(int i=begin+1;i<=end;i++){
        if(strcmp(min,arr[i]) > 0){
            min = arr[i];
            index = i; 
        }
    }
    return index;
}
void selection_sort(char *arr[],int len){
    for(int i=0;i<len;i++){
        int min_index = GetMinindex(arr,i,len-1);
        swap(arr+i,arr+min_index); //arr+i和arr+min_index是地址，不是值，所以要加**
    }
}

int main(){
    char *s[]={"hello", "world","good","morning","bye"};
    print(s,5);
    selection_sort(s,5);
    print(s,5);
    return 0;
}