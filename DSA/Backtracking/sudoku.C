#include <bits/stdc++.h>
using namespace std;

int puzzle[9][9] = 	   {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      	{0, 5, 0, 0, 9, 0, 6, 0, 0},
                      	{1, 3, 0, 0, 0, 0, 2, 5, 0},
                      	{0, 0, 0, 0, 0, 0, 0, 7, 4},
                      	{0, 0, 5, 2, 0, 6, 3, 0, 0} };

void printSudoku()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<puzzle[i][j]<<" ";
		cout<<endl;
	}
}
bool Find_Unassigned(int &row, int &col)
{
	for(row=0;row<9;row++)
	{
		for(col=0;col<9;col++)
		{
			if(puzzle[row][col]==0)
				return true;
		}
	}
	return false;
}

bool Solving_sudoku()
{
	bool flag = true;
	int row,col;
	if(!Find_Unassigned(row,col))
		return true;	//  sudoku is finally solved
	// Now fill the current unassigned position in sudoku (row, col) with any digit (0-9)
	// check the complete row
	cout<<row<<" "<<col<<endl;
	for(int i=1;i<=9;i++)
	{
		flag = true;
		for(int j=0;j<9;j++)
		{//   cout<<i<<" "<<puzzle[row][j]<<endl;
			// checking the row
			if(puzzle[row][j]==i)
			{   
				flag = false;
				break;
			}
		}
		if(flag)
		{
			// checking the column
			for(int j=0;j<9;j++)
			{
				if(puzzle[j][col]==i)
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
		{
			int start_row = row-row%3;
			int start_col = col-col%3;
			for(int k=start_row;k<(start_row+3);k++)
			{
				for(int l=start_col;l<(start_col+3);l++)
				{
					if(puzzle[k][l]==i)
					{
						flag=false;
						break;
					}
				}
					if(!flag)
						break;
			}
		}

		//cout<<flag_gridCheck<<endl;
		if(flag)
		{
			puzzle[row][col] = i;
			if(Solving_sudoku())
				return true;
			puzzle[row][col] = 0;

	   	}
	}
	return false;
}



int main()
{
    // 0 represent unassigned location
    if(Solving_sudoku())
    	printSudoku();
   	else
   		cout<<"No solution exists";
   	
   	return 0;
}