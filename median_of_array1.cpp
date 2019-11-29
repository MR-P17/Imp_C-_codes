#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;

}

int partition(int arr[],int l,int r)
{
	int pivot=arr[r];
	int i=l;

	for(int j=l;j<=r-1;j++)
	{
		if(arr[j]<=pivot)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[r]);
	return i;
}

int random_partition(int arr[],int l,int r)
{
	int m=rand()%(r-l+1);

	swap(&arr[l+m],&arr[r]);

	return partition(arr,l,r);
}

int kth_smallest(int arr[],int l,int r,int k)
{
	if(k>0 && k<=r-l+1)
	{
		int idx=random_partition(arr,l,r);

		if(idx-l==k-1)
			return arr[idx];

		if(idx-l>k-1)
			return kth_smallest(arr,l,idx-1,k);

		else
			return kth_smallest(arr,idx+1,r,k-idx-1+l);
	}
}

int main()
{
	int arr[]={7,10,4,3,20,15,17};
	int n=sizeof(arr)/sizeof(arr[0]);

	if(n%2!=0)
	{
		int x=kth_smallest(arr,0,n-1,n/2 +1);
		cout<<"median is: "<<x<<endl;
	}

	else
	{
		float y=kth_smallest(arr,0,n-1,n/2);
		float z=kth_smallest(arr,0,n-1,n/2 +1);
		float a=(y+z)/2;

		cout<<"median is: "<<a<<endl;
	}

	return 0;
}