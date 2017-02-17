
function convert(str){
	if (typeof str === 'string') {
		return str.replace(/\s/g,'%20');
	}
	else {
		return 'please input a string';
	}
}

//test


var str = 12;//没有输入字符串
var str1 = '';//空字符串
var str2 = 'a b';
var str3 = ' ';
var str4 = 'a  b';//连续连个空格;
var str5 = 'a	b';//tab;
console.log(convert(str));
console.log(convert(str1));
console.log(convert(str2));
console.log(convert(str3));
console.log(convert(str4));
console.log(convert(str5));
