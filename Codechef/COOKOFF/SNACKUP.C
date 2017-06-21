#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int no_of_judges;
	while(t--){
		cin>>no_of_judges;
		cout<<"2\n";
		cout<<no_of_judges<<endl;
		int k=1;
		for(int i=1;i<=no_of_judges;i++){
			for(int j=1;j<=no_of_judges;j++){
				cout<<i<<" "<<j<<" ";
			}
		}
	}
	return 0;
}