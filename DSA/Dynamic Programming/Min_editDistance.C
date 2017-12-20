//author @ Ayush Aggarwal
// Code for Minimum Edit distance
// Transform string A to string B using minimum operations
// Opeartions are - Insert, Replace, Delete
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	int len1 = str1.length();
	int len2 = str2.length();
	int mat[len1+1][len2+1];
	mat[0][0] = 0;
	for(int i=1;i<len1+1;i++)
		mat[0][i] = i;
	for(int i=1;i<len2+1;i++)
		mat[i][0] = i;
	for(int i=1;i<len2+1;i++)
	{
		for(int j=1;j<len1+1;j++)
		{
			if(str2[i-1]==str1[j-1])
				mat[i][j] =mat[i-1][j-1];
			else
				mat[i][j] = min(min(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1])+1;
		}
	}

	cout<<mat[len2][len1];
	return 0;	
}