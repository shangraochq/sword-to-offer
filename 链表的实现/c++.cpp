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