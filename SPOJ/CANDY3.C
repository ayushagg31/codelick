#include<iostream>
#include<stdio.h>
#define max 1000000007
using namespace std;
int main(){
unsigned long long int t,col,num,sum;
char c;
cin>>t;
//c = getchar();
for(int i=0;i<t;i++)
    {   cin>>col;
    	sum=0;
    	
    for(int j=0;j<col;j++)
    {
    	cin>>num;
        sum =(sum%col + num%col)%col;
//        sum = sum%(max);
       }
    if(sum%col!=0)
        cout<<"NO\n";
    else
    cout<<"YES\n";
    }
//	 cout<<endl;
//    c = getchar();
    }
    
 
