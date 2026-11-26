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

//获取尾节点的地址
Node* get_tail(Node* L)
{
    Node* p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

//尾插法
Node* insertTail(Node* tail, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = NULL;
    return p;
}

//在指定位置插入
int insertNode(Node *L, int pos, ElemType e)
{
    Node* p = L;
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if(p == NULL)
        {
            return 0;
        }
    }
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->prev = p;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;
    return 1;
}

//删除节点
int deleteNode(Node* L, int pos)
{
    Node* p = L;
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if(p == NULL)
        {
            return 0;
        }
    }
    if(p->next == NULL)
    {
        printf("要删除的位置错误\n");
        return 0;
    }
    Node* q = p->next;
    p->next = q->next;//修改前驱节点的后继
    q->next->prev = p;//修改后继节点的前驱
    free(q);
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

    Node *tail = get_tail(list);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);
    listNode(list);

    insertNode(list, 2, 15);
    listNode(list);

    deleteNode(list, 2);
    listNode(list);

    return 0;
}