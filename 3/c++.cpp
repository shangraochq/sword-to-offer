#include <iostream>	
using namespace std;
bool Find(int matrix[4][4], int rows, int columns, int number)
{
    bool found = false;

    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >=0)
        {
            if(matrix[row][column] == number)
            {
                found = true;
                break;
            }
            else if(matrix[row][column] > number)
                -- column;
            else
                ++ row;
        }
    }

    return found;
}


//test
int main(){
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	bool result;
	result = Find(matrix, 4, 4, 70);
	cout<<result<<endl;
	return 0;

}


//chq tests



