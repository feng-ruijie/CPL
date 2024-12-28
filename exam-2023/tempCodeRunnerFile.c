#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *right , *down; 
}node;
int n,m,T;
void buildline(node *head,int x){
    head = (node*)malloc(sizeof(node));
    head -> data = 0;  //虚拟节点的权值为0
    node *pre = head; 
    for(int i=1;i<=m;i++){
        node *now = (node *)malloc(sizeof(node));
        pre -> right = now;
        now -> data = x * m + i;
        now -> down = NULL; //初始化时，每行节点的down指针指向NULL
        pre = now; 
    }
}
void binddown(node *head1 ,node *head0){
    for(int i=1;i<=m;i++){
        node *now1 = head1 -> right , *now0 = head0 -> right;
        now0 -> down = now1; 
    }    
}
node *find(node *head,int x){
    node *now = head;
    for(int i=1;i<=m;i++){
        now = now -> right;
    }
    return now;
}
void change1(node *x1,node *x2,int x){
    for(int i=1;i<=x;i++){
        node *y1 = x1 -> down , *y2 = x2 -> down;
        x2 -> down = y1 , x1 -> down = y2;
        x1 = x1 -> right , x2 = x2 -> right;
    }
}
void change2(node *x1,node *x2,int x){
    for(int i=1;i<=x;i++){
        node *y1 = x1 -> right , *y2 = x2 -> right;
        x2 -> right = y1 , x1 -> right = y2;
        x1 = x1 -> down , x2 = x2 -> down;
    }
}
long long print(node *head){
    node *now = head; 
    long long sum = 0; 
    for(int i=1;i<=m;i++){
        now = now -> right;
        sum += now -> data;
    }
    return sum;
}
int main(){
    node *head[2505];
    scanf("%d%d];",n,m,T);
    for(int i=0;i<=n;i++){ //第0行为虚拟节点
        buildline(head[i],i); 
       // if(i >= 1) binddown(head[i] , head[i-1]);
    }
    while(T--){
        int x1,y1,x2,y2,x3,y3,x4,y4,a;
        scanf("%d %d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&a);
        node *x1_1y1 = find(head[x1-1],y1); //修改下向
        node *x3_1y1 = find(head[x3-1],y3);
        node *x1y1_1 = find(head[x1],y1-1); //修改右向
        node *x3y3_1 = find(head[x3],y3-1);
        
        node *x2_y1 = find(head[x2],y1); //修改下向
        node *x4_y3 = find(head[x4],y3);
        node *x1_y2 = find(head[x1],y2); //修改右向
        node *x3_y4 = find(head[x3],y4);

        change1(x1_1y1,x3_1y1,y2-y1+1); //修改下向,往右遍历
        change2(x1y1_1,x3y3_1,x2-x1+1); //修改右向,往下遍历
        change1(x2_y1,x4_y3,y4-y3+1);
        change2(x1_y2,x3_y4,x4-x3+1);

        printf("%lld\n",print(head[a]));
    }
}   