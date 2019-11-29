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

void count_sort(int arr[],int n,int pos)
{
	int freq[10]={0};

	for(int i=0;i<n;i++)
	freq[(arr[i]/pos)%10]++;

	for(int i=1;i<10;i++)
	freq[i]+=freq[i-1];

	int res[n];
	for(int i=n-1;i>=0;i--)
	{
		res[freq[(arr[i]/pos)%10]-1]=arr[i];
		freq[(arr[i]/pos)%10]--;
	}

	for(int i=0;i<n;i++)
	arr[i]=res[i];
}

void radix_sort(int arr[],int n)
{
	int m=find_max(arr,n);

	for(int pos=1;m/pos>0;pos*=10)
	{
		count_sort(arr,n,pos);
	}
}

int main()
{
	int arr[]={170, 45, 75, 90, 802, 24, 2, 66};
	int n=sizeof(arr)/sizeof(arr[0]);

	radix_sort(arr,n);

	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}