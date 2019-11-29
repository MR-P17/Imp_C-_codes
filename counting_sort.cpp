#include<bits/stdc++.h>
using namespace std;

int find_max(int arr[],int n)
{
	int m=arr[0];
	for(int i=1;i<n;i++)
		if(arr[i]>m)
			m=arr[i];

	return m;
}

void count_sort(int arr[],int n)
{
	int m=find_max(arr,n);
	int freq[m+1]={0};

	for(int i=0;i<n;i++)
		freq[arr[i]]++;

	for(int i=1;i<=m;i++)
		freq[i]+=freq[i-1];

	int res[n]={0};

	for(int i=n-1;i>=0;i--)
	{
		res[freq[arr[i]]-1]=arr[i];
		freq[arr[i]]--;
	}

	for(int i=0;i<n;i++)
	{
		arr[i]=res[i];
	}

}

int main()
{
	int arr[]={3,6,4,1,3,4,1,4};
	int n=sizeof(arr)/sizeof(arr[0]);

	count_sort(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}