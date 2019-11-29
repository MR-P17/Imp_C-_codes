#include<iostream>
using namespace std;

void multiply(int a[3][3],int b[3][3])
{
	int c[3][3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
            c[i][j]=0;
            for(int k=0;k<3;k++)
            {
            	c[i][j]+=a[i][k]*b[k][j];
            }
		}

		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				a[i][j]=c[i][j];
}

int power(int m[3][3],int n)
{
	int s[3][3]={{1,2,3},{1,0,0},{0,0,1}};

	if(n==1)
	return m[0][0]+m[0][2];

	int l=power(m,n/2);

	multiply(m,m);

	if(n%2!=0)
	multiply(m,s);

	return m[0][0]+m[0][2];

}

int main()
{
	int m[3][3]={{1,2,3},{1,0,0},{0,0,1}};
    int n;
    cin>>n;


	cout<<power(m,n-2)<<endl;
	return 0;
}