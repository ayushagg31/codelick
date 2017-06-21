#include <iostream>
using namespace std;

int main()
{
	int size,turn;
	cin>>size>>turn;
	int arr[size][size],b[size][size]={0};
	int x,y;
	int k=1;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			arr[i][j] = k;
			k++;
		}
	}
	while(turn--)
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				//apply rotation on final matrix
				y=i;
				x=size-j-1;
				b[i][j]=arr[x][y];
			//	cout<<b[i][j]<<endl;
			}
		}
		for(int i=0;i<size;i++)
		{
		for(int j=0;j<size;j++)
			arr[i][j] = b[i][j];
		}
	}
		int Ameen =0;
	for(int i=0;i<size;i++)
		 Ameen +=arr[0][i];
	int Sameh=0;
	for(int i=0;i<size;i++)
		 Sameh +=arr[i][0];
	int Shafeek=0;
	for(int i=0;i<size;i++)
		 Shafeek +=arr[i][size-1];
		int Atef=0;
	for(int i=0;i<size;i++)
		 Atef +=arr[size-1][i];
	if((Ameen > Sameh)&&(Ameen>Atef)&&(Ameen>Shafeek))
		cout<<"Ameen";
	else if((Sameh > Ameen)&&(Sameh>Atef)&&(Sameh>Shafeek))
		cout<<"Sameh";
	else if((Atef > Ameen)&&(Atef>Sameh)&&(Atef>Shafeek))
		cout<<"Atef";
	else
		cout<<"Shafeek";

	for(int i=0;i<size;i++)
	{
		cout<<endl;
		for(int j=0;j<size;j++)
			cout<<b[i][j]<<" ";
	}


	return 0;
}