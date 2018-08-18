function Node(value, left, right){
	this.value = value;
	this.left = left;
	this.right = right;

}
function BST(){
	this.root = null;
	this.insert = insert;
	this.inOrder = inOrder;
}
	
//插入节点
function insert(value){
	var insertNode = new Node(value, null, null);
	
	if (this.root == null) {
		this.root = insertNode;
	}
	else {
		var currentNode = this.root;
		var parent = null;
		while() {
			parent = currentNode;
			if (value < currentNode.value) {
				currentNode = currentNode.left;
				if (currentNode == null) {
					parent.left = insertNode;
				}
			}
			else {
				currentNode = currentNode.right;
				if (currentNode == null) {
					parent.right = insertNode;
					break;
				}
			}
		}
	}
}

//中序遍历 调用方法  BST1.inOrder(BST1.root)
function inOrder(node){
	if (node != null) {
		inOrder(node.left);
		print(node.value);
		inOrder(node.right);
	}
}

//先序遍历
function inOrder(node){
	if (node != null) {
		print(node.value);
		inOrder(node.left);
		inOrder(node.right);
	}
}

//后序遍历
function inOrder(node){
	if (node != null) {
		inOrder(node.left);
		inOrder(node.right);
		print(node.value);
	}
}

//查找最小值和最大值
function getMin(){
	var currentNode = this.root;
	if (currentNode == null) {
		return;
	}
	while(currentNode.left != null) {
		currentNode = currentNode.left;
	}
	return currentNode.value;
}

function getMax(){
	var currentNode = this.root;
	if (currentNode == null) {
		return;
	}
	while(currentNode.right != null) {
		currentNode = currentNode.right;
	}
	return currentNode.value;
}

//查找给定值
function find(value){
	var currentNode = this.root;
	if (currentNode == null) {
		return null;
	}
	while(currentNode != null){
		if (value == currentNode.value) {
			return currentNode;
		}
		else if (value < currentNode.value) {
			currentNode = currentNode.left;
		}
		else {
			currentNode = currentNode.right;
		}
	}
	return null;
}

//删除给定值节点





//面试题23 从上往下打印二叉树，即宽度优先遍历
function printFromToBottom(){
	if (this.root == null) {
		return;
	}
	var quene = new Queue();
	quene.enqueue(this.root);
	while(!quene.empty()){
		var currentNode = quene.front();
		print(currentNode.value);
		quene.dequeue();
		if (currentNode.left) {
			quene.enqueue(currentNode.left);
		}
		if (currentNode.right) {
			quene.enqueue(currentNode.right);
		}
	}
}