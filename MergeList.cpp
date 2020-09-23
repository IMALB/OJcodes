/*
* 内 容：合并两个非递减单链表,新链表非递减
* 最后修改日期：2020.09.22
*/
#include <iostream>
using namespace std;

struct LNode {
	int data;
	LNode *next;
};
typedef struct LNode *LinkList;

bool InitList(LinkList &L)
{
	L = new LNode;
	if (L == NULL)
		return false;
	L->next = NULL;  
	return true;
}
// 尾插法
LinkList CreatList(LinkList &L)
{
	int n;
	LNode *s = nullptr, *r = L;
	cout << "input the number of the list:";
	cin >> n;
	cout << "input the elem of the list:";
	for (int i = 0; i < n; i++) {
		s = new LNode;
		cin >> s->data;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}

// 有序链表合并，两两比较，非递减，连起来
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{ // 把Lb的节点插入La中
	LNode *pa = La->next;
	LNode *pb = Lb->next;
	LNode *pc = La;
	Lc = La;   
	while(pa && pb) {
		if (pa->data < pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		} else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}	
	}
	pc->next = pa ? pa : pb;
	delete Lb;
}

void PrintList(LinkList L)
{
	LNode *p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	LinkList La, Lb, Lc;
	InitList(La);
	InitList(Lb);
	
	CreatList(La);
	CreatList(Lb);
	MergeList(La, Lb, Lc);
	PrintList(Lc);
	return 0;
}