
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
function print(root) {
	if (root === null) {
		return;
	}
	var array = [];
	array.push(root);
	console.log(array.length);
	while(array.length !== 0){
		var pNode = array.shift();
		console.log(pNode.val);
		if (pNode.left) {
			array.push(pNode.left);
		}
		if (pNode.right) {
			array.push(pNode.right);
		}
	}
}

	``

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

//深复制
function DeepCopy(obj) {
	if (Object.prototype.toString.call(obj) === "[object Object]") {
		var result = {};	
		for (i in obj){
			result[i] = DeepCopy(obj[i]);
			console.log(1);
		}
		
		return result;
	}
	else if (Object.prototype.toString.call(obj) === "[object Array]") {
		var result = [];
		for(var i = 0; i < obj.length; i++) {
			console.log(3);
			result[i] = DeepCopy(obj[i]);
		}

		return result;
	}
	else {
		console.log(2);
		return obj;
	}
}

var chq1 = {
	a:1,
	b:2,
	c:[1,2,3]
}

chq2 = DeepCopy(chq1);
chq2.c.push(4);
console.log(chq1.c);
console.log(chq2.c);

//HelloWorld => hello_world
function fn(str) {
	var str = str.replace(/^\s*|\s*$/, '');
	var firstChar = str[0];
	str = str.replace(firstChar, firstChar.toLowerCase());
	arr = str.split('');
	var reg = /[A-Z]/;
	arr = arr.map(function(item){
		if (reg.test(item)) {
			return '_' + item.toLowerCase();
		}
		else return item;
	});
	str = arr.join('');
	return str;

}
fn(" HelloWorldMap");



//面试题41，和为s的两个数字
function FindNumberSum(arr, sum) {
	if (Object.prototype.toString.call(arr) === "object Array") {
		return;
	}
	var preIndex = 0, 
		LastIndex = arr.length -1;
	while(preIndex < LastIndex) {
		if (arr[preIndex] + arr[LastIndex] > sum) {
			LastIndex--;
		}
		else if (arr[preIndex] + arr[LastIndex] < sum) {
			preIndex++;
		}
		else {
			console.log("fisrtnumber:" + arr[preIndex] + ";" + "secondnumber:" + arr[LastIndex] );
			break;
		}
	} 
	return;
}
var arr = [1,2,4,7,11,15];
FindNumberSum(arr,3);



//面试题42，翻转单词顺序
function ReverseString(str) {
	var CopyString = "",
		length = str.length,
		i = length - 1;
	while(i > -1){
		CopyString += str[i];
		i--;
	}
	return CopyString;
}
function ReverseSentence(str){
	var CopySenatence = "",
		strArray = [];
	str = ReverseString(str);

	strArray = str.split(/\s+/);
	for(var i = 0; i < strArray.length; i++) {
		CopySenatence = CopySenatence + " " + ReverseString(strArray[i]) ;
	}
	return CopySenatence;


}
var string = "i am a student.";
ReverseSentence(string);

//面试题44，扑克牌的顺子·1
function isContinued(arr) {
	if (Object.prototype.toString.call(arr) !== "object Array") {
		return new Error("argument is not an Array");
	}
	var sortArr = arr.sort(function(a,b){
		return a-b;
	});
	var length = sortArr.length,
		zeroCount = 0;
	for(var i = 0; i < length; i++){
		if (sortArr[i] === 0) {
			zeroCount++;
		}
	}
	var gapCount = 0;
	for(var j = 0; j <length - 1; j++){
		if (sortArr[j] === sortArr[j + 1]) {
			return false;
		}
		gapCount += (sortArr[j + 1] - sortArr[j] - 1);
	}

	if (gapCount <= zeroCount) {
		return true;
	}
	else return false;


}
var arr = 1
isContinued(arr);



