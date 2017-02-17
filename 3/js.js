
function getpoint(arr,point){
	var rows = arr.length,
		columns = arr[0].length,
		row = 0,
		column = columns -1,
		found = false;
	while(row<rows&&column>-1){
		if (arr[row][column] == point) {
			break;
		}
		else if (arr[row][column] > point) {
			column--;
		}
		else{
			row++;
		}
	}
	return found ? [row, column] : "not found";
	
}

//test
var arr = [[1,2,8,9], [2,4,9,12], [4,7,10,13], [6,8,11,15]],
	result = [];
result = getpoint(arr,100);
result1 = getpoint(arr,7);
console.log(result);
console.log(result1);