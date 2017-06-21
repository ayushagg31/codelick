#include<iostream>
using namespace std;
int main(){
int a,b,c,out;
cin>>a>>b>>c;

while((a!=0)||(b!=0)||(c!=0)){
if((a!=b)&&(b!=c)){
if((c-b)== (b-a)){
int d = b-a;
out = a+3*d;
cout<<"AP "<<out<<endl;
}
else
{
int r = b/a;
//cout<<r;
out = c*r;
cout<<"GP "<<out<<endl;
}
}
cin>>a>>b>>c;
}
}
