#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=4;

	int arr[][n]={{1,2,3,4},
				  {5,6,7,8},
				  {9,10,11,12},
				  {13,14,15,16}};

	int sri=0,eri=n-1,sci=0,eci=n-1;

	while(sri<eri && sci<eci)
	{
		for(int i=sci;i<=eci;i++)
		cout<<arr[sri][i]<<" ";
		sri++;

		for(int i=sri;i<=eri;i++)
		cout<<arr[i][eci]<<" ";
		eci--;

		for(int i=eci;i>=sci;i--)
		cout<<arr[eri][i]<<" ";
		eri--;

		for(int i=eri;i>=sri;i--)
		cout<<arr[i][sci]<<" ";
		sci++;
	}

	cout<<endl<<" its done.."<<endl;

	return 0;
}