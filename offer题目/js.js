
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


//21包含Min函数的栈


//23从上往下打印二叉树
function print(rootNode) {
	if (rootNode === null) {
		return;
	}
	var array = [];
	arrar.push(rootNode);
	while(rootNode.length === 0){
		var pNode = array.shift();
		if (pNode.left) {
			array.push(pNode.left);
		}
		if (pNode.right) {
			array.push(pNode.right);
		}
	}
}

//31连续子数组的最大和
function findMax(array) {
	if (Object.prototype.toString.call(array) !== "[object Array]") {
		return;
	}
	var maxSum = array[0],
		currentSum = 0,
		length = array.length;
	if (length == 0) {
		return;	
	}
	for (var i = 0; i <length; i++) {
		if (currentSum <= 0) {
			currentSum = array[i];
		}
		else {
			currentSum += array[i];
		}
		if (currentSum > maxSum) {
			maxSum = currentSum;
		}
	}
	console.log(maxSum);
	// return maxSum;
}
//test
var array1 = [1,-1,3,10,-4,7,2,-5];
var array2 = [];
var array3 = [1];
var array4 = [-1,2,3,-5];
findMax(array1);
findMax(array2);
findMax(array3);
findMax(array4);



//34丑数
function getSomeUglyNumber(count) {
	if (count <= 0 || (typeof count).toLowerCase() != "number") {
		return;
	}
	var array = [];
	array[0] = 1;
	var currentCount = 1,
		index2 = 0,
		index3 = 0,
		index5 = 0;
	while(currentCount < count) {

		var min = Min(array[index2]*2, array[index3]*3, array[index5]*5);
		array[currentCount] = min;
		while(array[index2]*2 <= array[currentCount]) {
			index2++;
		}
		while(array[index3]*3 <= array[currentCount]) {
			index3++;
		}
		while(array[index5]*5 <= array[currentCount]) {
			index5++;
		}
		currentCount++;
	}
	return array[count -1];

}
function Min(num1, num2, num3) {
	if (num1 > num2) {
		return num2 > num3 ? num3 : num2;
	}
	else {
		return num1 > num3 ? num3 : num1;
	}
}

//35第一个只出现一次的字符
function FirstNoRepeatChar(string) {
	if (Object.prototype.toString.call(string) !== "[object String]") {
		console.log("请输入字符串");
	}
	var array = [];
	for(var i = 0; i < string.length; i++) {
		if (array[string.charCodeAt(i)] == undefined) {
			array[string.charCodeAt(i)] = 1;
			console.log(1);
		}
		else {
			array[string.charCodeAt(i)]++;
			console.log(2);
		}

	}

	for(var j = 0; j < string.length; j ++) {
		if (array[string.charCodeAt(j)] === 1) {
			return string[j];
			console.log(3);
		}
	}
}

//

