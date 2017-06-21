#include<iostream>
using namespace std;
void JULKA(unsigned long long int ,unsigned long long int );
int main()
{
	unsigned long long int total,k;
	for(int i=0;i<10;i++)
	{
		cin>>total>>k;
		JULKA(total,k);
	}
}
void JULKA(unsigned long long int total,unsigned long long int klaudia)
{
	unsigned long long int natalia;
	unsigned long long int diff,kla;
	kla = (total +klaudia)/2;
	natalia = total-kla;
	cout<<kla<<endl;
	cout<<natalia<<endl;
}
