#include <iostream>
using namespace std;

int main() {
		int t,n,k;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n],flag=0;
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cin>>k;
	    for(int i=0;i<n;i++)
	    if(a[i]==k)
	    {
	        cout<<i<<endl;
	        flag=1;
	    }
	    if(flag==0)
	     cout<<-1;
	}
	return 0;
}
