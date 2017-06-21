#include<iostream>
using namespace std;
int main()
{
	int m,n,min;
	int decide;
	cin>>n>>m;
	int A[n][m+2];
	int posrec1[n];
	int posrec2[n];
	string str;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		
		int temp=0;
		for(int j=m+1;j>=0;j--)
		{
			cin>>A[i][j];
			if((A[i][j]==1)&&(temp==0))
			{
				posrec1[i]=j;
				temp=1;
			}
			if(A[i][j]==1)
				posrec2[i]=j;	
		}
		if(temp==0)
		posrec2[i]=0;
    }   
    decide=posrec2[0];
    min=decide;
    for(int i=1;i<n;i++)
    {
    	if(posrec2[i]==0)
    	{
    		min=min+1;
    		continue;
    	}
    if((posrec2[i]+decide)>=(m+1-decide+m+1-posrec1[i]))
    {
    	min=min+m+1-posrec1[i]+m+1-decide+1;
    	decide=posrec1[i];
    }
    else
    {
     	min=min+decide+1+posrec2[i];
    	decide=posrec2[i];
    }
    }
    int sub=0;
    for(int i=n-1;i>=0;i--)
    {
    	if(posrec1[i]==0)
    		sub=sub+1;
    	if(posrec1[i]!=0)
    	break;
    }
    min=min-sub;
    cout<<min;
	return 0;
}                        