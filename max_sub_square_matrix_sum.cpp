#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int arr[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>arr[i][j];

	int temp[n-k+1][n];

	for(int i=0;i<n-k+1;i++)
	{
		for(int j=0;j<n;j++)
		{
			temp[i][j]=0;
			for(int l=i;l<k+i;l++)
			temp[i][j]+=arr[l][j];
		}
	}

	int max=INT_MIN;

	for(int i=0;i<n-k+1;i++)
	{
		int sum=0;
		for(int l=0;l<k;l++)
		sum+=temp[i][l];

		if(max<sum)
		max=sum;

		for(int j=k;j<n;j++)
		{
			sum-=arr[i][j-k];
			sum+=arr[i][j];

			if(max<sum)
			max=sum;
		}
	}
	cout<<max<<endl;
}