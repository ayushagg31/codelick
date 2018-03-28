//author @ Ayush Aggarwal
// N queen problem
// Description:  Place N Queens on a NxN chess-board such that no-one intersect each other
// Topic: Recursion and Backtraking
#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int> > res;
//row , column
bool Nqueen_prob(int n, int row)
{
	if(n==row)
		return true;
	for(int col=0;col<n;col++)
	{
		bool flag = true;
		for(int queen=0;queen<row;queen++)
		{
			if(res[queen].first == row or res[queen].second == col or (res[queen].first +res[queen].second == row+col) 
				or (res[queen].first - res[queen].second == row-col))
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			if(row +1 > res.size())
				res.push_back(make_pair(row,col));
			else
			{
				res[row].first = row;
				res[row].second = col;
			}
			if(Nqueen_prob(n,row+1))
				return true;
		}
	}
	return false;
}

int main()
{	
	int n; // n represents number of queen and size of chessboard
	cin>>n;	// currently we are operating on 4*4 chessboard for simplicity
	// conditions for intersection between two queen
	// > Horizontal case: Row value is same
	// > Vertical case: Column value is same
	// > Anti-Diagonal Case: Row+Column value is same
	// > Diagonal Case: Row-Column value is same
	bool solution =Nqueen_prob(n,0);
	if(solution)
	{
		for(int i=0;i<res.size();i++)
			cout<<"("<<res[i].first<<","<<res[i].second<<")"<<endl;
	}
	else
		cout<<"No solution exist"<<endl;

	// Nqueen_prob(number of queen, starting row, resulting vector)
	return 0;	
}