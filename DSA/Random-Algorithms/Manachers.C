/*author @ Ayush Aggarwal
***https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
***https://www.youtube.com/watch?v=kbUiR5YWUpQ&t=638s
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE 100010
int palin[SIZE*2+1];
void manachers(string P,string Q)
{
	int c=0,r=0;
	int len = Q.length();
	for(int i=0;i<len;i++)
	{
		int mirror = c-(i-c);
		if(r > i)
			palin[i] = min(palin[mirror],r - i);
		while(P[i+1+palin[i]] == P[i-1-palin[i]])
			palin[i]++;
		if(i + palin[i] > r)
		{
			r = i+palin[i];
			c = i;
		}
	}
	//int max_length= max_element(palin,palin+len);
	int centre_index =max_element(palin,palin+len) - palin;
	int max_length = palin[centre_index];
	cout<<max_length<<endl;
	cout<<Q.substr((centre_index - max_length)/2,max_length);
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str = "acncanc";
	string newstring = "";
	for(int i=0;i<str.length();i++)
		newstring += "#"+str.substr(i,1);
	newstring +="#";
	manachers(newstring,str);
	return 0;
}