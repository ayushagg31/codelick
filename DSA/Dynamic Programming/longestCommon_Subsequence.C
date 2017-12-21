//author @ Ayush Aggarwal
// Longest common subsequence
#include <bits/stdc++.h>
using namespace std;
int lcs(string str1, string str2)
{
  int m = str1.length();
  int n = str2.length();
  int L[m+1][n+1];
    
   for (int i=0; i<=m; i++)
   {
   		for (int j=0; j<=n; j++)
     	{
       		if (i == 0 || j == 0)
         	L[i][j] = 0; 
       		else if (str1[i-1] == str2[j-1])
         		L[i][j] = L[i-1][j-1] + 1;
       		else
         		L[i][j] = max(L[i-1][j], L[i][j-1]);
     	}
   }
   return L[m][n];
}  
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
  	string str1,str2;
  	cin>>str1>>str2;
  
  	cout<<"Length of LCS is "<< lcs(str1,str2);
  	return 0;
}