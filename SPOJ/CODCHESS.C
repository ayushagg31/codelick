#include <iostream>
using namespace std;

int main() {
	
	// your code here
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		if(n%2==0)
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}

	return 0;
}
