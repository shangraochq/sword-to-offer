//二分查找
function binSearch(arr, data) {
	if (!(arr instanceof Array)) {
		console.log("请输入一个数组");
	}
	var upperBound = arr.length -1;
	var lowerBound = 0;
	while(lowerBound <= upperBound){
		
		var middlePoint = Math.floor((lowerBound + upperBound)/2);
		if (data < arr[middlePoint]) {
			upperBound = middlePoint - 1;
		}
		else if (data > arr[middlePoint]) {
			lowerBound = middlePoint +1;
		}
		else {
			return middlePoint;
		}
	}
	
}

var a = [1,2,3,4,5];
console.log(binSearch(a,3));