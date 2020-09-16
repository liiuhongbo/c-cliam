#include <iostream>
using namespace std;//iostrenmt用法更新
#include <stdio.h>
#include <stack>


//向链表的末尾添加一个节点 
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


//书上的例子，未验证pHead为空的情况
void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}

ListNode* CreateLink(int a[], int k)//创建单链表
{
	ListNode* Head = NULL, * q = NULL;
	for (int i = 0; i < k; i++)
	{
		ListNode* pNew = new ListNode();
		pNew->m_nValue = a[i];
		pNew->m_pNext = NULL;

		if (Head == NULL)
		{
			Head = pNew;
			q = pNew;
		}
		else
		{
			q->m_pNext = pNew;
			q = q->m_pNext;
		}
	}
	return Head;
}
//从头到尾打印列表
void printLink(ListNode* pHead)
{
	ListNode* p = pHead;
	while (p)
	{
		cout << p->m_nValue << " " << endl;
		p = p->m_pNext;
	}
	cout << endl;//endl就是end line的区别，也就是“结束此行”，但实际上有两个操作

	              //1 换行

		          //2 对缓冲流进行冲刷，使得流中所有剩余字符被写入输出序列。
}
void main()
{
	int a[] = { 1,2,3 };
	ListNode* Head = CreateLink(a, 3);
	printLink(Head);

	AddToTail(&Head, 6);
	printLink(Head);
}