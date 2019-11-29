#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int partition(int arr[],int l,int r,int mi)
{
	swap(&arr[mi],&arr[r]);
	int pivot=arr[r];

	int i=l;

	for(int j=l;j<=r-1;j++)
	{
		if(arr[j]<=pivot)
		{
			swap(arr[i],arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[r]);
	return i;
}

int find_median(int arr[],int n)
{
	sort(arr,arr+n);

	return arr[n/2];
}

int kth_smallest(int arr[],int l,int r,int k)
{
	if(k>0 && k<=r-l+1)
	{
		int n=r-l+1,i;

		int median[(n+4)/5];

		for(i=0;i<n/5;i++)
		{
			median[i]=find_median(arr+l+5*i,5);
		}

		if(5*i<n)
		{
			median[i]=find_median(arr+l+5*i,n%5);
			i++;
		}


		int mid_idx=((i==1)?0:kth_smallest(median,0,i-1,i/2));


		int idx=partition(arr,l,r,mid_idx);

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
	int arr[]={7,10,4,3,20,15,17,13};
	int n=sizeof(arr)/sizeof(arr[0]);

	if(n%2!=0)
	{
		int x=kth_smallest(arr,0,n-1,n/2 +1);
		cout<<"median is: "<<x<<endl;
	}

	else
	{
		float y=(float)kth_smallest(arr,0,n-1,n/2);
		float z=(float)kth_smallest(arr,0,n-1,n/2 +1);
		float a=(y+z)/2;

		cout<<"median is: "<<a<<endl;
	}

	return 0;
}