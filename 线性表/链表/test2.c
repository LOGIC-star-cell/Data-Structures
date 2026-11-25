#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

//定义双向链表
typedef struct node
{
    ElemType data;
    struct node *next, *prev;
}Node;

//初始化双向链表
Node* initList()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

//头插法
int insertHead(Node *L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if(L->next != NULL)//判断这个链表中不只是有头节点，还有后继
    {
        L->next->prev = p;
    }
    L->next = p;
    return 1;
}

//遍历
void listNode(Node* L)
{
    Node* p = L->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Node *list = initList();

    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);
    listNode(list);
    return 0;
}