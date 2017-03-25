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

//17合并两个排序的链表
ListNode* mergeSortList(ListNode* pHead1, ListNode* pHead2) {

	if (pHead1 == NULL)
	{
		return pHead2;
	}
	else if (pHead2 == NULL)
	{
		return pHead1;
	}
	ListNode* pMergeHead = NULL;
	if (pHead1->value >= pHead2->value)
	{
		pMergeHead = pHead2;
		pMergeHead->next = mergeSortList(pHead1, pHead2->next);
	}
	else {
		pMergeHead = pHead1;
		pMergeHead->next = mergeSortList(pHead1->next, pHead2);
	}
	return pMergeHead;
}

//18树的子结构
 void isChildStruct(ListNode* pFatherRoot, ListNode* pChildRoot) {
 	bool result = false;
 	if (pFatherRoot != NULL && pChildRoot != NULL)
 	{
 		if (pFatherRoot == pChildRoot)
 		{
 			result = true;
 		}
 		else {
 			isChildStruct(pFatherRoot->left, pChildRoot);
 			isChildStruct(pFatherRoot->right, pChildRoot); 
 		}
 	}
 	return result;
 }

 //19二叉树的镜像
 void mirrorBinaryTree(BinaryTreeNode* pNode) {
 	if (pNode == NULL)
 	{
 		return;
 	}

 	if (pNode->left == NULL && pNode->right == NULL)
 	{	
 		return;
 	}
 	BinaryTreeNode* temp = pNode->left;
 	pNode->left = pNode->right;
 	pNode->right = temp;
 	mirrorBinaryTree(pNode->left);
 	mirrorBinaryTree(pNode->right);
 }

 //20顺时针打印矩阵



 //23从上往下打印二叉树
 void printFromTopToBottom(BinaryTreeNode* pRoot){
 	if (pRoot == NULL)
 	{
 		return;
 	}
 	std::deque <BinaryTreeNode *> dequeTree;
 	dequeTree.push_back(pRoot);
 	while(dequeTree.size()){
 		BinaryTreeNode* pNode = dequeTree.pop_front();
 		print(pNode->value);
 		if (pNode->left != NULL)
 		{
 			dequeTree.push_back(pNode->left);
 		}
 		if (pNode->right != NULL)
 		{
			dequeTree.push_back(pNode->right);
 		}

 	}
 	
 }

 //24二叉搜索树的后序遍历序列
 bool verifySquenceOfBst(int *squence, int length){
 	if (squence == NULL || length <= 0)
 	{
 		return false;
 	}
 	int root = squence[length - 1];
 	int i;
 	for(int i = 0; i < length; i++) {
 		if (squence[i] > root) 
 		{
 			break;
 		}
 	}

 	int j = i;
 	for(; j< length; j++) {
 		if (squence[j] < root)
 		{
 			return false;
 		}
 	}
 	bool left = true;
 	if (i > 0 )
 	{
 		left = verifySquenceOfBst(squence, i);
 	}
 	bool right = true;
 	if (i < length -1)
 	{
 		right = verifySquenceOfBst(squence + i, length - i - 1);
 	}
 	return left&&right;
 }


 //25二叉树和为某一值得路径
 

 //26二叉搜索树和双向链表


 //31连续子数组的最大和
 bool isInvalidInput = false;
int findMax(int * pData, int length) {
	if (pData == NULL || length <= 0) {
		isInvalidInput = true;
		return 0;
	}
	int maxSum = pData[0];//记录最大值
	int currentSum = 0;//记录当前值得和
	for(int i = 0; i < length; i++) {
		if (currentSum <= 0)
		{
			currentSum = pData[i];
		}
		else {
			currentSum += pData[i];
		}
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
		}
	}
	isInvalidInput = true;
	return maxSum;
}




//39二叉树深度
int getDepthOfTree(BinaryTreeNode* pRoot) {

	if (pRoot == NULL)
	{
		return 0;
	}
	int leftDepth = getDepthOfTree(pRoot->left);
	int rightDepth = getDepthOfTree(pRoot->right);
	return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
}

//39的题目二
bool isBalanceTree(BinaryTreeNode* pRoot) {

	if (pRoot == NULL)
	{
		return true;
	}
	int leftDepth = getDepthOfTree(pRoot->left);
	int rightDepth = getDepthOfTree(pRoot->right);
	int diff = leftDepth - rightDepth;
	if (diff > 1 || diff < -1)
	{
		return false;
	}

	return isBalanceTree(pRoot->left)&&isBalanceTree(pRoot->right);


}







