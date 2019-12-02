#include <iostream>
using namespace std;

void wavePrint(int input[][100], int row, int col)
{
    int j=0;
    for(int i = 0 ; i< col ; i++)
    {
        while(j<row && j>=0)
        {
            cout << input[j][i]<<" ";
            if(i%2 == 0)
            j++;
            else
            j--;
        }
        if(i%2 == 0)
            j--;
            else
            j++;
    }
    return;
}

int main() 
{
    int input[150][100];
    int row, col;
    cin >> row >> col;
    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    wavePrint(input, row, col);
    return 0;
}