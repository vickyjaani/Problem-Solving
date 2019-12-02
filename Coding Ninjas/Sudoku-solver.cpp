#include<iostream>
using namespace std;
bool isValid(int board[][9], int row, int col)
{
    // check row & col 
    for(int i = 0; i<9 ; i++)
    {
        if ( i != col)
        {
            if(board[row][i] == board[row][col])
                return false;
        }
        if( i!= row)
            if(board[i][col] == board[row][col])
                return false;        
    }
    
    // check in small box 3 x 3
    int x = row - row%3;
    int y = col - col%3;
    int z = x+3;
    int w = y+3;
    for( x ; x < z ; x++)
    {
        for( y ; y < w ; y++)
        {
            if( x != row && y != col)
            {
                if(board[x][y] == board[row][col])
                    return false;
            }
        }
    }
    return true;
}



bool sudokuSolver(int board[][9] , int row = 0, int col = 0){
    if(row == 9)
        return true;
    if(board[row][col] == 0)
    {
        for(int i = 1; i < 10 ; i++)
        {   
            board[row][col] = i;
            if(isValid(board , row , col))
            {
                if(col+1 == 9)
                {
                    if( sudokuSolver(board, row + 1, col - 8))
                        return true;
                }
                else
                    if( sudokuSolver(board, row , col + 1))
                        return true;
            }
        }
        
        board[row][col] = 0;

        return false;
    }
    if(col+1 == 9)
    {
        return sudokuSolver(board, row + 1, col - 8);
    }
    else
        return sudokuSolver(board, row , col + 1);
}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}