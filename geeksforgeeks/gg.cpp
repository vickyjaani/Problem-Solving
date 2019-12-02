#include<iostream>
using namespace std;



int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n,temp,m;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		m=n;
		for(int i=0;i<n-1;i++)
		{
			temp=a[m-1];
			for(int j=0;j<m;j++)
			{
				a[m-1-j]=a[m-2-j];
			}
			a[0]=temp;

			for(int j=m-i-1;j<m-1;j++)
			{
				if(j<0)
				j=0;
				a[j]=a[j+1];
			}
			m-=1;
		}
		cout<<a[0];
		t--;
	}
}
