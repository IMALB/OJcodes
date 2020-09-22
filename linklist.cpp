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

// 头插创建链表
LinkList CreatList1(LinkList &L)
{
    LNode *t = new LNode;    // 临时节点
    int cnt; // 节点个数
    cout << "input count of linklist:";
    cin >> cnt;
    cout << "input number of linklist:" << endl;
    for (int i = 0; i < cnt; i++) {
        cin >> t->data;
        t->next = L->next;
        L->next = t;
    }
    return L;
}

// 求表长
int Length(LinkList L)
{
    LNode *t = L;
    int len = 0;
    if (t->next != NULL) {
        len++;
        t = t->next;
    }
    return len;
}

// 打印链表
void PrintLint(LinkList L)
{
    LNode *t = L->next;
    while (t != NULL) {
        cout << t->data << endl;
        t = t->next;
    }
}
int main()
{
    LNode *t = new LNode;
    cout << "sada" << endl;
    t->data = 10;
    cout << "asdada" << endl;
    cout << t->data << "asdas" << endl;
    
    // LinkList L;
    // InitList(L);
    // CreatList1(L);

    // PrintLint(L);
    return 0;
}