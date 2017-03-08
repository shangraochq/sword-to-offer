//14调整数组顺序使奇数位于偶数前面
#include <iostream>
using namespace std;
void orderOddEven(int *pData, int length) {
	if (pData == NULL || length <=0)
	{
		return;
	}
	int *pBegin = pData,
		*pEnd = pData + length -1;
	while(pBegin < pEnd) {
		while(pBegin < pEnd && *pBegin%2 != 0){
			pBegin++;
		}

		while(pBegin < pEnd && *pEnd%2 == 0){
			pEnd--;
		}
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

void printArray(int *pData, int length){
	if (pData == NULL || length <= 0)
	{
		return;
	}
	for(int i = 0; i < length; i++){
		cout<< pData[i]<<endl;
	}
}
int main(){
	int numbers[] = {};
	orderOddEven(numbers,sizeof(numbers)/4);
	printArray(numbers,sizeof(numbers)/4);
	return 0;
}

//16反转链表
ListNode * reverseList(ListNode* pHead){
	if (pHead == NULL)
	{
		return NULL;
	}
	ListNode * pPre = NULL;
	ListNode * pNode  = pHead;
	ListNode * pReverseHead = NULL;  

	while(pNode != NULL){
		ListNode * pNext = pNode->next;
		if (pNext == NULL)
		{
			pReverseHead = pNode;
		}
		pNode->next = pPre;
		pPre = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}