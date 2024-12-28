#ifndef LL_H
#define LL_H
typedef struct node{
    int val;
    struct node *next;
}Node;

typedef struct ll{
    Node *head;
    Node *tail;
}Linkerlist;

void init(Linkerlist *ll);
void Free(Linkerlist *ll);
int IsEmpty(Linkerlist *ll);
int IsSignal(Linkerlist *ll);
void Append(Linkerlist *ll, int val);
void Print(Linkerlist *ll);
void KillUntilOne(Linkerlist *list);
void Delete(Linkerlist *ll, Node *prev);
int GetSurvivor(Linkerlist *ll);


#endif //LL_H