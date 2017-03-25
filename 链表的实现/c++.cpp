#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node * next;
};

//向后生成链表
Node * createdown(){
	int data;
	Node * head, * tail, *p;
	head = new Node();
	head->next = NULL;
	tail = head;
	while(cin>>data){
		p = new Node();
		p->value = data;
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
	return head;
}

//向前生成链表
Node * createup(){
	int data;
	Node * head,*p;
	head = new Node();
	head->next = NULL;
	while(cin>.data){
		p = new Node();
		p->value = data;
		p->next = head->next;
		head->next = p;
		
	}
	return head;
}

//按照数据查找
Node * find(Node *head, int value){
	Node * p;
	p = head->next;
	while(p != NULL && p->value != value){
		p = p->next
	}
	return p;//如果p为NULL，则未找到
}

//在p节点之后插入一个信息域为x的节点
void insert(Node *p, int x){
	Node *q = new Node();
	q->value = x;
	q->next = p->next;
	p->next = q;

}

//删除节点p后面的节点
void del(Node *p){
	Node * q;
	q = p->next;
	p->next = q->next;
	delete q;
}

//反转链表 
Node * reverseList(Node * head){
	Node* reverseHead = NULL;
	Node* p = head->next;//我的链表在链首有一个空节点
	Node* preNode = NULL;
	Node* nextNode = NULL;
	if(p != NULL){
		while( p->next != NULL){
				nextNode = p->next;
				p->next = preNode;
				preNode = p;
				p = nextNode;
			}
		head->next = p;
		}
	
	return head;
}

//输出链表中倒数第K个节点（没有定义空的头结点的）
Node * FindKthToTail(Node * pHead, unsigned int k){
	if(pHead == NULL || k==0){
		return Null;
	}
	Node * pAhead = pHead;
	Node * pBehind = Null;
	for (int i = 0; i < k -1; ++i)
	{
		pBehind = pAhead->next;
		if (pBehind == Null)
		{
			return NULL;
		}
	}
	while(pBehind->next != NULL){
		pBehind = pBehind->next;
		pAhead = pAhead->next;
	}

	return pAhead;


}

//在O(1)时间删除链表节点，给定了头指针和一个节点指针（没有定义空的头结点）
void  deleteNode(Node* phead, Node* pToBeDelete){
	if (pHead == Null || pToBeDelete ==Null)
	{
		return;
	}
	if (pToBeDelete->next != Null)
	{
		Node * pNext = pToBeDelete->next;
		pToBeDelete->value = pNext->value;
		pToBeDelete->next = pNext->next;
		delete pNext;
		pNext = Null;
	}
	else if(pHead == pToBeDelete){
		delete pToBeDelete;
		pToBeDelete = Null;
		pHead = Null;
	}
	else {
		Node * pNode = pHead;
		while(pNode->next != pToBeDelete){
			pNode = pNode->next;
		}
		pNode->next = Null;
		delete pToBeDelete;
		pToBeDelete = Null;
	}
}

//面17
Node * merge(Node* pHead1, Node* pHead2){
	if (pHead1 == Null)
	{
		return pHead2;
	}
	else if (pHead2 == Null){
		return pHead1;
	}
	Node* mergeNode  = Null;
	if (pHead1->value < pHead2->value)
	{
		mergeNode = pHead1;
		mergeNode->next = merge(pHead1->next, pHead2);
	}
	else {
		mergeNode = pHead2;
		mergeNode->next =merge(pHead1, pHead2->next);
	}
	return mergeNode;
}

//从头到尾打印链表 面试题5
//解法一
void printReverse(Node* pHead){
	if (pHead == Null)
	{
		return;
	}
	Node* currentNode = pHead;
	std::stack<Node*> Nodes;
	while(currentNode != Null){
		Nodes.push(currentNode);
		currentNode = currentNode->next;
	}

	while(!Nodes.empty()){
		currentNode = Nodes.pop();
		cout<<currentNode->value<<endl;
	}
}

//解法二
void printReverse(Node* pHead){
	if (pHead == Null)
	{
		return;
	}
	if (pHead->next != Null)
	{
		printReverse(pHead->next);
	}
	cont<<pHead->value<<endl;
}
