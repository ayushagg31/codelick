/*author @ Ayush Aggarwal
*** https://www.youtube.com/watch?v=CpZh4eF8QBw
*** https://github.com/mission-peace/interview/blob/master/src/com/interview/string/ZAlgorithm.java
*** Time Complexity : O(m+n)
*** Space Complexity: O(m+n)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Z[1000];
int total_length=0;
void calculateZ(char str[],int len)
{
	int left=0,right=0;
	Z[0] = 0;
	for(int k=1;k<len;k++)
	{
		if(k > right)
		{
			right = left = k;
			while(right < len and str[right]==str[right-left])
				right++;
			Z[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k-left;
			if(Z[k1] < right - k + 1) 
                    Z[k] = Z[k1];
            else 
            {
            	left = k;
                while(right < len and str[right] == str[right - left])
                	right++;
                Z[k] = right - left;
                right--;
            }
        }
	}
}
void ZAlgorithm(string text,string pattern)
{
	total_length = text.length() + pattern.length() + 1;
	char new_string[total_length];
	int i=0;
	for(i=0;i<pattern.length();i++)
		new_string[i] = pattern[i];
	new_string[i] = '$';
	i++;
	for(int j=0;j<text.length();j++)
	{
		new_string[i] = text[j];
		i++;
	}
	calculateZ(new_string,total_length);
}
int main()
{	
	string text = "aaabcxyzaaaabczaaczabbaaaaaabc";
	string pattern = "aaabc";
	vector <int> result;
	ZAlgorithm(text,pattern);
	for(int i=0;i<total_length;i++)
	{
		if(Z[i]==pattern.length())
			result.push_back(i - pattern.length() - 1);
	}
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<endl;
	return 0;
}