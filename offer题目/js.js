
//13在O(1)时间删除链表节点
function deleteNode(pHead, pToBeDeleted) {
	if (!pHead || !pToBeDeleted) {
		return
	}

	if (pToBeDeleted.next !== null) {
		var pNextNode = pToBeDeleted.next;
		pToBeDeleted.next = pNextNode.next;
		pToBeDeleted.value = pNextNode.value;
		pNextNode.next = null;
	}
	else if (pHead === pToBeDeleted) {
		delete pHead;
	}
	else {
		var pNode = pHead;
		while(pNode.next !== pToBeDeleted){
			pNode = pNode.next;
		}
		pNode.next = null;
		delete pToBeDeleted;
	}
}


//14调整数组顺序使奇数位于偶数前面
function orderOddEven(array) {
	if (Object.prototype.toString.call(array) !== "[object Array]") {
		return;
	}
	var length = array.length;
	if (length === 1) {
		return;
	}
	console.log(1);
	var oddArray = [],
		evenArray = [];
	for (var i = 0; i < length; i++) {
		if (array[i]%2 === 0) {
			evenArray.push(array[i]);
		}

		else {
			oddArray.push(array[i]);
		}
	}
	return [].concat(oddArray, evenArray);
	
}
//test
var array = [1,2,-3,4,-5,-6,7,8];
array = orderOddEven(array);
console.log(array);
