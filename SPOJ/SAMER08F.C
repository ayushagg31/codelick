#include<iostream>
using namespace std;
int main(){
int x,out;
cin>>x;
while(x!=0){
out = (x*(x+1)*(2*x+1))/6;
cout<<out<<endl;
cin>>x;
}
}
