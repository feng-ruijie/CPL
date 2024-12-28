#include "ll.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void init(Linkerlist *ll){
    ll -> head = NULL;
    ll -> tail = NULL;
}
int IsEmpty(Linkerlist *ll){
    return ll -> head == NULL; 
}
void Free(Linkerlist *ll){
    while(!IsEmpty(ll)){
        Delete(ll,ll -> head);
    }
}
int IsSignal(Linkerlist *ll){
    return ll -> head == ll -> tail;
}
void Print(Linkerlist *ll){
    Node *node = ll -> head; 
    if(IsEmpty(ll)){
        return; 
    }
    while(1){
        printf("%d ",node -> val);
        node = node -> next; 
        if(node == ll -> head) break; 
    }
    printf("\n");
}
void Append(Linkerlist *ll, int n){
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL) return; 
    node -> val = n; 
    
    if(IsEmpty(ll)){
        ll -> head = node; 
        ll -> tail = node; 
        ll -> tail -> next = ll -> head; 
    }
    else{
        ll -> tail -> next = node; 
        ll -> tail = node;
        node -> next = ll -> head;
    }
}
void Delete(Linkerlist *ll, Node *prev){
    if(IsEmpty(ll)) return; 
    if(IsSignal(ll)){
        free(ll -> head);
        init(ll);
        return;
    }
    Node *cur = prev -> next; 
    Node *next = cur -> next; 
    prev -> next = next;
    
    if(cur == ll -> head){
        ll -> head = next;
    }
    if(cur == ll -> tail){
        ll -> tail = prev;
    }
    free(cur); 
}
void KillUntilOne(Linkerlist *list){
    Node *node = list -> head;
    while(!IsSignal(list)){
        Delete(list , node);
        node = node -> next;
    }
}
int GetSurvivor(Linkerlist *ll){
    return ll -> head -> val;
}