//冒泡排序
function bubbleSort(arr) {
	var length = arr.length;
	var tmp;
	for( var i = length - 1; i > 0; i--){
		var flag = 0;
		for( var j = 0; j < i; j++){
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				flag = 1;
			}
		}

		if (flag == 0) {
			break;
		}
	}
}

//选择排序
function selectSort(arr) {
	var length = arr.length;
	for (var i = 0; i < length-1; i++){
		var min = i;
		for (var j = i +1; j < length; j++){
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			var tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

//直接插入排序
function insertSort(arr) {
	
	for (var i = 1; i < arr.length; i++){
		for (var j = i - 1; j >= 0; j--){
			if (arr[j] <= arr[i]) {
				break;
			}
		}

		if (j != i - 1) {
			var tmp = arr[i];
			for (var k = i - 1; k > j; k--){
				arr[k+1] = arr[k];
			}
			arr[k+1] = tmp;
		}
	}
}


//快速排序
function qSort(arr)
{
	if (arr.length == 0) {
		return [];
	}
	var left = [];
	var right = [];
	var pivot = arr[0];
	for (var i = 1; i < arr.length; i++) {

		if (arr[i] < pivot) {
			left.push(arr[i]);
		} 
		else {
			right.push(arr[i]);
		}
	}
	return qSort(left).concat(pivot, qSort(right));
}


//希尔排序

