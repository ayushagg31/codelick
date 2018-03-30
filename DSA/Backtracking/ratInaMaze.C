//author @ Ayush Aggarwal
// Rat in a Maze 
// Description: Help rat to move from source to destination in a maze
// Topic: Recursion and Backtracking
#include <bits/stdc++.h>
using namespace std;
#define N 4
int res[N][N] = { {0, 0, 0, 0},
      			  {0, 0, 0, 0},
        		  {0, 0, 0, 0},
        		  {0, 0, 0, 0}
    			};	// our soution for maze puzzle
// This function checks whether it is possible to move the rat to forward or downward
bool checkSafe(int maze[N][N], int row, int col)
{
	// check for forward movement
	if(maze[row][col] == 1 and row< N and col< N and row>=0 and col>=0)
		return true;
	return false;

}
bool MazeSolverUtil(int maze[N][N],int row,int col)
{
	if(row==N-1 and col==N-1)
	{
		res[row][col] = 1;
		return true;
	}
	if(checkSafe(maze,row,col))
	{
		res[row][col] = 1;
		if(MazeSolverUtil(maze,row,col+1))
			return true;
		else if(MazeSolverUtil(maze,row+1,col))
			return true;
		res[row][col] = 0;
		return false;
	}
	return false;
}
void print_Maze()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
void MazeSolver(int maze[N][N])
{
	// source = (0,0)
	// destination = (N-1,N-1)
	if(MazeSolverUtil(maze,0,0))
	{
		print_Maze();
		return;
	}
		cout<<"Unfortunately rat remains puzzled"<<endl;
}
int main()
{
	// consider maze input as this... where 0 represent Gray blocks(dead end) 
	// and 1 represents White blocks(opening)
	int maze[N][N]  =  { {1, 0, 0, 0},
      					 {1, 1, 1, 1},
        			     {0, 1, 0, 1},
        				 {1, 1, 1, 1}
    				    };

    // Let's create a function to solve this maze puzzle
    MazeSolver(maze);
   	// MazeSolver(maze matrix, start row, start column)

	return 0;	
}