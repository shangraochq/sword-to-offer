function Stack(){
	this.dataStore = [];
	this.peek = 0;
	this.pop = pop;
	this.push = push;
	this.top = top;
	this.isEmpty = isEmpty;
}

function pop(){
	if (!this.isEmpty) {
		return this.dataStore[--this.peek];
	}
}

function push(data) {
	this.dataStore[this.peek++] = data;
}

function top() {
	return this.dataStore[this.peek-1];
}

function isEmpty() {
	return this.peek == 0 ? true : false;
}


//十进制转化为2-9镜子
function numBased(num, base) {
	var s = new Stack();
	while(num > 0) {
		s.push(num % base);
		num  = Math.floor(num/2);
	}
	var result = '';
	return result += s.pop();
}



