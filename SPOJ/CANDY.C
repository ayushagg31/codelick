#include<iostream>
using namespace std;
int main(){
int t;
while(1)
{
float sum=0;
float mean;
cin>>t;
if(t==-1)
    break;
else{
int a[t];
for(int i=0;i<t;i++)
    {   
        cin>>a[i];
        sum +=a[i];
    }
//    cout<<"\n"<<sum<<endl;
    mean = sum/t;
   // cout<<mean<<endl;
    int data = mean;
    //cout<<data<<endl;
    if(mean != data)
        cout<<"-1"<<endl;
    else
    {
    	//can be distributed equally in this case
    	int mov=0;
    	for(int i=0;i<t;i++)
    	{
    		if(a[i]<data)
	    		mov += data-a[i];
    	}
    	cout<<mov<<endl;
	}
}
}
}
