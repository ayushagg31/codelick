//author @ Ayush Aggarwal
//Calculate Sum in a given Range for Q queries
//Ref : http://www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair <pair <int,int> , int > p[100005];
int block_size;
bool compare(pair <pair <int,int> , int > &p1,pair <pair <int,int> , int > &p2)
{
	int p1_L = p1.first.first/block_size;
	int p2_L = p2.first.first/block_size;
	if(p1_L != p2_L)
		return p1_L < p2_L;
	return p1.first.second < p2.first.second;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,Q;
	cin>>N>>Q;
	int a[N],L,R;
	for(int i=0;i<N;i++)
		cin>>a[i];
	for(int i=0;i<Q;i++)
	{
		cin>>p[i].first.first>>p[i].first.second;
		p[i].second = i;
	}
	block_size = sqrt(N);
	int sum[Q];
	memset(sum,0,sizeof(sum));
	sort(p,p + Q,compare);
	int currSum=0,currL=0,curr_R=0;
	for(int i=0;i<Q;i++)
	{
		L = p[i].first.first;
		R = p[i].first.second;
		while(currL < L)
		{
			currSum -=a[currL];
			currL++;
		}
		while(currL > L)
		{
			currSum += a[currL-1]; 
			currL--;
		}
		while(curr_R > R+1)
		{
			currSum -=a[curr_R];
			curr_R--;
		}
		while(curr_R <= R)
		{
			currSum +=a[curr_R];
			curr_R++;
		}
		sum[p[i].second] = currSum;
	}
	for(int i=0;i<Q;i++)
		cout<<sum[i]<<endl;
	return 0;
}