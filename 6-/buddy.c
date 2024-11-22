#include<stdio.h>
int n,q,v[10007],pre[10007],nxt[10007],a[10007];
int prod(int m){
    int s = (1<<30);
    while(s >= m){
        s >>= 1;
    }
    if(s == 0) return 1;
    return s << 1;
}
int main(){
    //printf("%d %d %d %d %d",prod(1),prod(2),prod(3),prod(4),prod(5));
    scanf("%d %d",&n,&q);
    int head = 1 , tot = 1;
    nxt[head] = 0;
    v[head] = (1<<n);
    while(q--){
        char op;
        scanf(" %c",&op);
        if(op == 'Q'){
            printf("%d\n",tot);
            for(int i=head;i;i=nxt[i]){
                printf("%d ",a[i]);
            } 
            printf("\n");   
        }
        else{
            int id,m;
            scanf(" %d %d",&id,&m);
            int need = prod(m);
            for(int i=head;i;i=nxt[i]){
           //     printf("%d ",i);
                if(a[i]) continue;
                while(v[i] > need){//分裂,向后分裂一个
                    //printf("%d ",need);
                    tot ++; 
                    nxt[tot] = nxt[i];
                    nxt[i] = tot;
                    v[i] >>= 1; 
                    v[tot] = v[i];
                }
                if(v[i] == need){
                    a[i] = id;
                    break;
                }
            }
          //  printf("\n");
        }
    }
}
