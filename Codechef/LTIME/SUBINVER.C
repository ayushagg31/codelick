#include <bits/stdc++.h>
using namespace std;

void comp(char ch[],int L,int R)
{
	for(int i=L;i<=R;i++)
	{
		if(ch[i]=='0')
			ch[i] = '1';
		else
			ch[i] = '0';
	}
}
int calc(char ch[],int len)
{
	int sum=0,count=0;
	for(int i=len-1;i>=0;i--)
	{
		if(ch[i] =='1')
			sum +=1<<count;
		count++;
	}
	return sum;
}
int main()
{
	int N,U,L,R;
	vector <int> v;
	vector <string> s;
	cin>>N>>U;
	string str[U+1];
	char ch[N];
	v.push_back(0);
	for(int i=0;i<N;i++)
		ch[i] = '0';
	cout<<ch;
	//strcpy(str[0],ch);
	string str1(ch);
	s.push_back(str1);
	int i=1;
	while(U--)
	{
		cin>>L>>R;
		comp(ch,L,R);
		cout<<ch<<endl;
		//strcpy(str[i],ch);
		i++;
		string str(ch);
		s.push_back(str);
		v.push_back(calc(ch,N));
	}
	cout<<s[distance(v.begin(),max_element(v.begin(),v.end()))];

}