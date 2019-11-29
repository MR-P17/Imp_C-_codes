#include<bits/stdc++.h>
using namespace std;
#define N 9

bool find_unassigned_loc(int grid[N][N],int &row,int &col)
{
	for(row=0;row<N;row++)
	for(col=0;col<N;col++)
	if(grid[row][col]==0)
	return true;

	return false;
}
bool safe_in_row(int grid[N][N],int row,int num)
{
	for(int col=0;col<N;col++)
	if(grid[row][col]==num)
	return false;

    return true;
}

bool safe_in_col(int grid[N][N],int col,int num)
{
	for(int row=0;row<N;row++)
	if(grid[row][col]==num)
	return false;

    return true;
}

bool safe_in_3by3_box(int grid[N][N],int row_,int col_,int num)
{
	for(int row=0;row<3;row++)
	for(int col=0;col<3;col++)
	if(grid[row+row_][col+col_]==num)
	return false;

	return true;
}

bool is_safe(int grid[N][N],int row,int col,int num)
{
	return (safe_in_row(grid,row,num) &&
		    safe_in_col(grid,col,num) &&
		    safe_in_3by3_box(grid,row-row%3,col-col%3,num) &&
		    grid[row][col]==0);
}

bool solve_sudoku(int grid[N][N])
{
	int row,col;

	if(!find_unassigned_loc(grid,row,col))
	return true;

	for(int num=1;num<=9;num++)
	{
		if(is_safe(grid,row,col,num))
		{
			grid[row][col]=num;

			if(solve_sudoku(grid))
			return true;

			grid[row][col]=0;
		}
	}
	return false;
}

void print_sudoku(int grid[N][N])
{
	for(int row=0;row<N;row++){
	for(int col=0;col<N;col++)
	cout<<grid[row][col]<<" ";
	cout<<endl; }
}


int main()
{
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if(solve_sudoku(grid)==true)
    print_sudoku(grid);  
	else
		cout<<"No solution exist.."<<endl;
	return 0;
}