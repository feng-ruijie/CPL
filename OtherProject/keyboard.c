#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char c;
    struct Node *pre,*next,*ls;
}node;

typedef struct Linkerlist{
    struct Node *head , *tail , *lasts , *lastl;
}list;

void init(list *ll){
    ll -> head = NULL;
    ll -> tail = NULL;
    ll -> lasts = NULL;
    ll -> lastl = NULL; 
}

int isEmpty(list *ll){
    return ll -> head == NULL;
}
int add(list *ll,char c){
    node *p = (node *)malloc(sizeof(node)); 
    p -> c = c;
    if(isEmpty(ll)){
        ll -> head = p;
        ll -> tail = p; 
        if(c >= 'a' && c <= 'z'){
            ll -> lasts = p; 
        } 
        else{
            ll -> lastl = p;
        }
        p -> pre = NULL;
        p -> next = NULL;
        p -> ls = NULL; //只有一个，肯定没有上一个相同的
    }
    else{
        p -> pre = ll -> tail;
        ll -> tail -> next = p;
        p -> next = NULL;
        if(c >= 'a' && c <= 'z'){
            p -> ls = ll -> lasts;
            ll -> lasts = p; 
        }
        else{
            p -> ls = ll -> lastl; 
            ll -> lastl = p; 
        }
        ll -> tail = p;
    }
}
int issignal(list *ll){
    return ll -> head == ll -> tail;
}
void delete_upper(list *ll){
    if(ll -> lastl == NULL) return; //没有，则不删除
    if(issignal(ll)){
        free(ll -> head);
        init(ll); 
        return; 
    }
    //现在要删除lastl这个节点
    node *cur = ll -> lastl;
    if(cur == ll -> head){ //头结点
        ll -> head = cur -> next;
        cur -> next -> pre = NULL;
        ll -> lastl = NULL; //最后一个小写字母不存在
    }
    else if(cur == ll -> tail){ //尾结点
        cur -> pre -> next = NULL; 
        ll -> tail = cur -> pre;
        ll -> lastl = cur -> ls; 
    }
    else{ //不涉及头尾指针的变动
        cur -> pre -> next = cur -> next;
        cur -> next -> pre = cur -> pre;
        ll -> lastl = cur -> ls;
    }
    free(cur); 
}
void delete_lower(list *ll){
    if(ll -> lasts == NULL) return; //没有，则不删除
    if(issignal(ll)){
        free(ll -> head);
        init(ll); 
        return; 
    }
    //现在要删除lasts这个节点
    node *cur = ll -> lasts;
    if(cur == ll -> head){ //头结点
        ll -> head = cur -> next;
        cur -> next -> pre = NULL;
        ll -> lasts = NULL; //最后一个小写字母不存在
    }
    else if(cur == ll -> tail){ //尾结点
        cur -> pre -> next = NULL; 
        ll -> tail = cur -> pre;
        ll -> lasts = cur -> ls; 
    }
    else{ //不涉及头尾指针的变动
        cur -> pre -> next = cur -> next;
        cur -> next -> pre = cur -> pre;
        ll -> lasts = cur -> ls;
    }
    free(cur); 
}
void print(list *ll,int x){
    int cnt = 0;
    char *s = (char *)malloc(sizeof(char)*2000005);
    node *p = ll -> tail;
    while(p != NULL && cnt < x){
        s[cnt++] = p -> c;  
        p = p -> pre;
    }
    for(int i=cnt-1;i>=0;i--) printf("%c",s[i]);
    printf("\n");
    free(s);
}
int main(){
    int n;
    scanf("%d",&n);
    list ll; 
    init(&ll);
    getchar();
    while(n--){
        char *s = (char*)malloc(sizeof(char)*2000005);
        scanf("%s",s);
        if(s[0] == '?'){
            int k;
            scanf("%d",&k);
            print(&ll,k);
        }
        else{
            int len = strlen(s);
            for(int i=0;i<len;i++){
                if(s[i] == 'M'){
                    delete_upper(&ll);
                }
                else if(s[i] == 'm'){
                    delete_lower(&ll);
                }
                else add(&ll,s[i]);
            }
        }
        free(s);
        getchar();
    }   
}

