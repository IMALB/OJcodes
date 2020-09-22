/*
* 内 容：单链表
* 最后修改日期：2020.09.22
*/

#include <iostream>
using namespace std;
#define ElemType int

struct LNode
{
    ElemType data;
    LNode* next;
};
typedef struct LNode* LinkList; // 链表的头节点

// 初始化链表
bool InitList(LinkList &L)
{ // 带头节点,头节点不存放数据
    L = new LNode;
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

// 判断是否空
bool Empty(LinkList L)
{
    if (L->next == NULL)
        return true;
    return false;
}

// 求表长
int Length(LinkList L)
{
    LNode *t = L;
    int len = 0;
    while (t->next != NULL) {
        len++;
        t = t->next;
    }
    cout << "tht length of th linklist:" << len << endl;
    return len;
}

// 打印链表
void PrintLint(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 头插创建链表（链表的顺序和输入的顺序相反）
LinkList CreatList1(LinkList &L)
{
    LNode *s = nullptr;      // 节点指针
    int cnt;                 // 节点个数
    cout << "input count of linklist:";
    cin >> cnt;
    cout << "input number of linklist:" << endl;
    for (int i = 0; i < cnt; i++) {
        s = new LNode;
        cin >> s->data;
        s->next = L->next;
        L->next = s;
    }
    return L;
}

// 尾插法创建链表
LinkList CreatList2(LinkList &L)
{
    LNode *s = nullptr, *r = L;  // r为表尾指针
    int cnt;
    cout << "input count of linklist:";
    cin >> cnt;
    cout << "input number of linklist:" << endl;
    for (int i = 0;i < cnt; i++) {
        s = new LNode;
        cin >> s->data;
        r->next = s;
        r = s;
    }
    r->next = NULL;            // 尾指针置空
    return L;
}

// 按序号查找节点值，返回第i个节点的指针(头节点是0)
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    if (i == 0)
        return L;
    LNode *p = L;
    int j = 0;    // 目前的位置计数
    while (p && j<i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找，返回第一个值为e的节点的指针
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;       // 若没有则是null
}

// 插入，元素e作为新链表的第i个位置插入(后插)
bool ListInsert(LinkList &L, int i, int e)
{
    LNode *p = GetElem(L, i - 1);
    if (!p)
        return false;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除节点，删除第i个元素，并用e返回值
bool ListDelete(LinkList &L, int i, int &e)
{
    LNode *p = GetElem(L, i - 1);
    if (p==NULL || !(p->next) )   // 删除位置不合理
        return false;
    LNode *q = p->next;          //  q是需要删除的节点
    
    p->next = q->next;
    e = q->data;
    delete q;
    return true;
}
int main()
{
    int e;
    LinkList L = nullptr;
    InitList(L);
    CreatList2(L);
    Length(L);
    PrintLint(L);

    LNode *N = nullptr;
    N = GetElem(L, 3);
    N = LocateElem(L, 4);

    if (ListInsert(L, 5, 5))
        PrintLint(L);
    else
        cout << "Insert Error" << endl;

    ListDelete(L, 6, e);
    PrintLint(L);
    return 0;
}