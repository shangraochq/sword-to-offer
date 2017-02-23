function verifySquenceOfBST(array){
	if (array.length == 0) {
		return false;
	}
	var length = array.length;
	var rootNode = array[length - 1];
	for(var i =0; i < length -1; i++){
		if (array[i] > rootNode) {
			break;
		}
	}

	var j = i;
	for (j; j < length - 1; j++) {
		if (array[j] < rootNode) {
			return false;
		}

	}

	var left = true;
	if (i >0 ) {
		left = verifySquenceOfBST(array.slice(0,i));
	}

	var right = true;
	if (i < length-1) {
		right = verifySquenceOfBST(array.slice(i,length-1));
	}

	return left&&right;
}


var arr2 = [1,2,3,5,4];
verifySquenceOfBST(arr2);
