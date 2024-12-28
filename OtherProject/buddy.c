#include <stdio.h>
#include <stdlib.h>
int n,q;
typedef struct Node{
    int data , id;
    struct Node *next;
}node; 
typedef struct Link{
    struct Node *head;
    int num;
}link;
void init(link *l){
    node *p = (node *)malloc(sizeof(node)); 
    p -> data = 1 << n;
    p -> next = NULL; 
    p -> id = 0;
    l -> head = p; 
    l -> num = 1;
}
void print(link *l){
    printf("%d\n",l -> num);
    node *p = l -> head; 
    node *q = p; 
    while(p != NULL){
        printf("%d ",p -> id);
        p = p -> next;
    } 
    printf("\n");
    while(q != NULL){
        printf("%d ",q -> data);
        q = q -> next;
    }
    printf("\n");    
}
void split(node *p){
    node *next = p -> next; // p 原本的下一个节点
    node *new = (node *)malloc(sizeof(node));
    new -> data = p -> data;
    new -> next = next; 
    p -> next = new; 
    new -> id = 0; 
}
void work(link *l,int id,int m){
    node *p = l -> head; 
    while(p != NULL){
        if(p -> data < m || p -> id != 0){ //p已经被用
            p = p -> next;
        }
        else{
            node *first = p;
            while(p -> data > m && (p -> data) / 2 >= m){ //分裂的情况
            p -> data /= 2;
            split(p);
            l -> num ++; 
            }
            if(p -> data >= m && p -> id == 0){ //可以存
            first -> id = id;
            return;
            }
        }
    }
}
int main(){
    link l;
    scanf("%d %d\n",&n,&q);
    init(&l); 
    while(q--){
        char c;
        scanf("%c",&c);
        if(c == 'A'){
            int x,y;
            scanf("%d %d",&x,&y);
            work(&l,x,y);
        }
        if(c == 'Q'){ //遍历
            print(&l); 
        }
        getchar();
    }
}
