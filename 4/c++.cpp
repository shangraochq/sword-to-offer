#include <iostream>
using namespace std;

//length is the volume of the arrar
void RepalceBlank(char string[], int length){
	if (string == NULL || length <= 0)
	{
		return;
	}

	//get the actual length
	int actualLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while(string[i] != '\0'){
		actualLength++;
		if (string[i] == ' ')
		{
			numberOfBlank++;
		}
		i++;
	}

	//get the new actual length
	int newLength = actualLength + numberOfBlank*2;
	if (newLength > length)
	{
		return;
	}

	int indexOfActual = actualLength;
	int indexOfNew = newLength;

	while(indexOfActual >= 0 && indexOfNew > indexOfActual){
		if (string[indexOfActual] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else {
			string[indexOfNew--] = string[indexOfActual];
		}
		indexOfActual--;
	}
	return;
}

int main(){

}


//test 
void Test(char* testName, char string[], int length, char expected[]){
	if (testName != NULL)
	{
		cout<<testName<<" beigin:";
	}
	RepalceBlank(string, length);
	if(expected == NULL && string == NULL)
		cout<<"passed"<<endl;
    else if(expected == NULL && string != NULL)
        cout<<"failed"<<endl;
    else if(string == expected)
        cout<<"passed"<<endl;
    else
        cout<<"failed"<<endl;
}

void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    char string1[] = "hello%20world";
    Test("Test1", string, length, string1);
}
// 空格在句子开头
void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// 传入NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}