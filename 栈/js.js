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