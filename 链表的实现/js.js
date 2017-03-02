//Node类
function Node(data) {
	this.value = data;
	this.next = null;
}

//LinkedList
function LinkedList(){
	this.head = new Node('head');
}
LinkedList.prototype = {
	constructor: LinkedList,
	find: function(data){
		var currentNode = this.head;
		while(currentNode.value != data){
			currentNode = currentNode.next;
		}
		return currentNode;
	},
	insert: function(newValue, data){
		var currentNode = this.find(data);
		var newNode = new Node(newValue);
		newNode.next = currentNode.next;
		currentNode.next = newNode;
		console.log(currentNode.next.value);

	},
	findPrevious: function(data){
		var currentNode = this.head;
		while( currentNode.next != null && currentNode.next.value != data){
			currentNode = currentNode.next;
		}
		if (currentNode.next != null) {
			return currentNode;
		}
		else {
			return null;//返回Null则表示未找到相应元素
		}
	},
	remove: function(data){
		var previousNode = this.findPrevious(data);
		if (previousNode == null) {
			print("do not find");
			return;
		}
		previousNode.next = previousNode.next.next;
	},
	display: function(){
		var currentNode = this.head;
		while(currentNode.next =! null) {
			console.log(1);
			print(currentNode.next.value);
			currentNode = currentNode.next;
		}
	}
}

function print(data){
	console.log(data);
}


//反转链表
function reverseList(list){
	var head = list.head;
	var node = head.next;
	var previousNode = null;
	var nextNode = null;
	if (node == null) {
		return list;
	}
	while(node.next != null){
		nextNode = node.next;
		node.next = previousNode;
		previousNode = node;
		node = nextNode;
	}
	head.next = node;
	return list;
}

//test

var cities = new LinkedList();
cities.insert("Conway", "head");
cities.insert("Russellville", "Conway");
cities.insert("Alma", "Russellville");
cities.display();



//从尾到头打印链表
function printFromTailToHead(Head) {
	var arr = [];
	var pNode = Head;
	while(pNode.next !== null) {
		arr.push(pNode.next);
		pNode = pNode.next;
	}
	var length = arr.length;
	while(length > 0){
		console.log(arr.pop());
		length--;
	}
}