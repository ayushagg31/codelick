//author @ Ayush Aggarwal
// String Permutation
// Description: Print all possible string permutation for a given string in lexographic order
// Topic : Recursion and Backtracking
#include <bits/stdc++.h>
using namespace std;
vector<string> output;
int level = 0;
int r_length = 0;
void string_permutation(char st[],int count[],char result[], int level,int len)
{
	if(level==r_length)
	{
		output.push_back(result);
		return;
	}
	for(int i=0;i<len;i++)
	{
		if(count[i]==0)
			continue;
		result[level] = st[i];
		count[i]--;
		string_permutation(st,count,result,level+1,len);
		count[i]++;
	}
}

int main()
{
	string str;
	cin>>str;
	map <char,int> mp; // count the occurance of character
	int len = str.length();
	r_length = len;
	for(int i=0;i<len;i++)
	{
		if(mp.find(str[i])== mp.end())
			mp.insert(pair <char,int>(str[i],1));
		else
			mp[str[i]]++;
	}
	int mp_len = mp.size();
	char st[mp_len];
	int count[mp_len];
	map <char, int> :: iterator itr;
	int i=0;
	for(itr = mp.begin();itr!=mp.end();itr++)
	{
		st[i] = itr->first;
		count[i] = itr->second;
		// cout<<st[i]<<" "<<count[i]<<" ";
		i++;
	}
	char result[len];
	string_permutation(st,count,result,level,mp_len);
	cout<<output.size()<<" ";
	for(int i=0;i<output.size();i++)
		cout<<output[i]<<" ";

	return 0;	
}