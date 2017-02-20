//二分查找
int binSearch(int arr[], int length, int value){
	if (arr == NULL || length <= 0)
	{
		return -1;
	}
	int upperBound = length -1;
	int lowerBound = 0;
	int middlePoint = 0;
	while(lowerBound <= upperBound){
		middlePoint = (upperBound + lowerBound)/2;
		if (arr[middlePoint] > value)
		{
			upperBound = middlePoint -1;
		}
		else if (arr[middlePoint] < value)
		{
			lowerBound = middlePoint +1;
		}
		else {
			return middlePoint;
		}
	}
	return -1;
}

//二分查找递归实现
int binSearch(int arr[], int lowerBound, int upperBound, int value){
	if (arr == NULL || lowerBound > upperBound)
	{
		return -1;
	}
	int middlePoint = (lowerBound + upperBound)/2;
	if (value > arr[middlePoint])
	{
		binSearch(arr, middlePoint +1, upperBound, value);
	}
	else if (value < arr[middlePoint])
	{
		binSearch(arr,lowerBound, middlePoint -1, value);
	}
	else {
		return middlePoint;
	}
}