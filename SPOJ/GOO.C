#include<iostream>
#include<stdio.h>
using namespace std;
#define i64 unsigned long long
i64 dp[66][33];
i64 nCr(int n, int r)
   {
           if(n==r) return dp[n][r] = 1;
           if(r==0) return dp[n][r] = 1;
           if(r==1) return dp[n][r] = (i64)n;
           if(dp[n][r]) return dp[n][r];
        return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
    }
//int out =1;
void GOO(int );
//int caculate(int ,int );
//int factorial(int );
int main()
{
	int t,a;
	cin>>t;
	for(int i=0;i<t;i++)
	{	//out =1;
		cin>>a;
		GOO(a);
	}
}
void GOO(int n)
{
	unsigned long long int no_of_possible_cases=0,no_of_ones=0,col;
	for(int i=1;i<=n;i++)	
	{
		col = nCr(n-1,i-1);
		no_of_possible_cases +=	col;
		no_of_ones += i*col;
	}
	cout<<no_of_possible_cases<<" "<<no_of_ones<<endl;
}
 /*int main()
    {
        int n, r;
        while(scanf("%d %d",&n,&r)==2)
             {
                     r = (r<n-r)? r : n-r;
                     printf("%llu\n",nCr(n,r));
             }
        return 0;
    }*/

