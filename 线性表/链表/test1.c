#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}Node;

//创建头节点,初始化链表
Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
int insertHead(Node* L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

//获取尾节点的地址
Node* get_tail(Node *L)
{
    Node *p = L;
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
    tail->next = p;
    p->next = NULL;
    return p;
}


Node* insertTailWithNode(Node* tail, Node* node)
{
    tail->next = node;
    node->next = NULL;
    return node;
}

//在指定位置插入数据
int insertNode(Node* L, int pos, ElemType e)
{
    //用来保存插入位置的前驱节点
    Node *p = L;
    //遍历链表找到插入位置的前驱节点
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        //防越界判断：如果还没走到pos-1步,p就变成了NULL
        if(p == NULL)
        {
            return 0;//插入位置错误
        }
    }
    //要插入的新节点
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

//删除指定位置的节点
int deleteNode(Node* L, int pos)
{
    //要删除节点的前驱
    Node *p = L;
    //遍历链表找到要删除节点的前驱
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
    //q指向要删除的节点
    Node *q = p->next;
    //让要删除节点的前驱指向要删除节点的后继
    p->next = q->next;
    //释放要删除节点的内存空间
    free(q);
    return 1;
}

//获取单链表的长度
int listLength(Node* L)
{
    Node* p = L->next;
    int len = 0;
    while(p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//释放单链表（保留头节点） 
void freeList(Node *L)
{
    Node* p = L->next;
    Node* q;

    while(p != NULL)
    {
        q = p->next;//先保存下一节点的地址
        free(p);//释放当前节点
        p = q;//p跳到下一节点
    }
    L->next = NULL;//头节点置空，防止野指针
}

//使用双指针寻找倒数第k个节点
Node* findNodeFS(Node* L, int k)
{
    Node* fast = L->next;
    Node* slow = L->next;
    for(int i = 0; i < k; k++)
    {
        fast = fast->next;
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("倒数第%d个节点值为：&d\n", k, slow->data);
}

//删除绝对值相同的节点
void removeNode(Node* L, int n)
{
    Node *p = L;
    int index;//作为数组下标使用
    int *q = (int*)malloc(sizeof(int) * (n + 1));

    //遍历数组，初始化为0
    for(int i = 0; i < n + 1; i++)
    {
        *(q + i) = 0;
    }

    while ((p->next != NULL))
    {
        index = abs(p->next->data);
        if(*(q + index) == 0)
        {
            *(q + index) = 1;
            p = p->next;
        }
        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}

//反转链表
Node* reverseList(Node* head)
{
    Node* first = NULL;
    Node* second = head->next;
    Node* third;

    while(second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    Node* hd = initList();//造一个新的头节点
    hd->next = first;

    return hd;
}

//删除链表中间节点（快慢指针）
int delMiddleNode(Node* head)
{
    Node *fast = head->next;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *q = slow->next;
    slow->next = q->next;
    free(q);

    return 1;
}

//判断链表是否有环
int isCycle(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            return 1;
        }
    }
    return 0;
}

//找到链表环的入口
Node* findBegin(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    //先判断链表有没有环
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            Node *p = fast;
            int count = 1;
            while(p->next != slow)
            {
                count++;
                p = p->next;
            }

            fast = head;
            slow = head;

            for(int i = 0; i < count; i++)
            {
                fast = fast->next;
            }
            
            while(fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

//遍历
void listNode(Node *L)
{
    Node *p = L->next;
    while(p != NULL)
    {
        printf("%d\n",p->data);//访问当前节点的数据
        p = p->next;//指针移到下一个节点
    }
    printf("\n");
}

int main()
{
    Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 20);

    Node *tail = get_tail(list);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail ,30);
    listNode(list);
    insertNode(list, 2, 15);
    listNode(list);

    deleteNode(list, 2);
    listNode(list);

    printf("%d\n",listLength(list));

    freeList(list);
    printf("%d\n",listLength(list));

    findNodeFS(list, 3);

    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    Node *three = tail;
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 8);
    tail = insertTail(tail, 9);
    tail->next = three;

    if(isCycle(list))
    {
        printf("有环\n");
    }
    else
    {
        printf("无环\n");
    }

    Node *p = findBegin(list);
    printf("%d\n", p->data);

    return 0;
}