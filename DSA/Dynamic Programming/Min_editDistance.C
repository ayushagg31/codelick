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
	//mat[0][0] = 0;
	for(int i=0;i<len1+1;i++)
	{
		for(int j=0;j<len2+1;j++)
		{
			if(i==0)
				mat[i][j]= j;
			else if(j==0)
				mat[i][j]= i;
			else if(str2[i-1]==str1[j-1])
				mat[i][j] =mat[i-1][j-1];
			else
				mat[i][j] = min(min(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1])+1;
		}
	}

	cout<<mat[len1][len2];
	return 0;	
}
