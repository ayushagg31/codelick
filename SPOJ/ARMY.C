#include<iostream>
using namespace std;
int maximum(int a[],int size);
int main()
{
	int t;
	cin>>t;
	int NG,NM;
	for(int i=0;i<t;i++)
	{
		cin>>NG>>NM;
		int G[NG],M[NM];
		for(int i=0;i<NG;i++)
			cin>>G[i];
		for(int i=0;i<NM;i++)
			cin>>M[i];
		int max1 = maximum(G,NG);
		int max2 = maximum(M,NM);
		if(max2>max1)
			cout<<"MechaGodzilla"<<endl;
		else
			cout<<"Godzilla"<<endl;
	}
}
int maximum(int a[],int size)
{
	int max = a[0],temp;
	for(int i=1;i<size;i++)
	{
		if(a[i]>max)
		{
			temp = max;
			max = a[i];
			a[i] = max;
		}
	}
	return(max);
	
}
