#include<stdio.h>

typedef struct Tree{
    int a,b,c;
}tree;
void work(int *b){
    b[0] = 10;
    b[1] = 20;
    b[2] = 30;
    return;
}
int main(){
  /* int a = 5 , *b;
    printf("%d %d",b,*b);*/
    int a = 123 , *b = &a;
    *b = 456;
    printf("%d %d\n",*b,a);
  /*  tree t = {1,2,3} , tr = {6,7,8};
    tree *p = &t;
    (*p) = tr;
    (*p).a = 4;
    p -> c = 5; 
    printf("%d %d %d\n",p->a,p->b,p->c);
    return 0;*/
  /* int a[3] = {1,2,3};
    int *p = a;
    *p = 4; //4 , 2 , 3 
    p = p + 1;
    *p = 5;
    p ++;
    *p = 6;
    printf("%d %d %d",a[0],a[1],a[2]);*/
  /*  int a[3] = {1,2,3};
    work(a);
    printf("%d %d %d",a[0],a[1],a[2]);
    return 0;*/
   /* int a = 6 , *p = &a; //毫无意义 
    *p ++;
    printf("%d",&p);*/
    
}