//author @ Ayush Aggarwal
// Tutorial link : https://www.youtube.com/watch?v=GTJr8OvyEVQ
// Code link :https://github.com/mission-peace/interview/blob/master/src/com/interview/string/SubstringSearch.java
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int lps[1000];
void computeTemporaryArray(string pattern)
{
	//int lps[pattern.length()];
	int index =0 ;
	for(int i=1;i<pattern.length();)
	{
		if(pattern[i] == pattern[index])
		{
			lps[i] = index+1;
			index++;
			i++;
		}
		else
		{
			if(index !=0)
				index = lps[index - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	//return lps;
}

bool KMP(string text,string pattern)
{
	/*int* lps = */computeTemporaryArray(pattern);
	int i=0,j=0;
	while(i < text.length() and j < pattern.length())
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
	if( j == pattern.length())
		return true;
	return false;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str = "abcxabcdabcdabcy";
	string substring = "abcdabcy";
	bool result = KMP(str,substring);
	cout<<result<<endl;
	return 0;
}