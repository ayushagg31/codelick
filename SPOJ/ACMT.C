#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int xp,nb;
	for(int i=0;i<t;i++)
	{
		cin>>xp>>nb;
		int max ,min;
		if(xp>nb)
			{ max = xp;
				min =nb;
				}
				
		else
			{
				max = nb;
				min = xp;
			}	
		if(max==0||min==0)	
			cout<<"0\n";
		else if(max/min>=2)
			cout<<min<<endl;
		else
			cout<<(max+min)/3<<endl;
			
			}	
	}
