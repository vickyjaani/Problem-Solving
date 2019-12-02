
#include <iostream>
using namespace std;

int main() {
	int t,n,count,major,ans;
	cin>>t;
	while(t){
	    cin>>n;
	    count=1,major=0;
	    
	    int A[n];
	    for(int i=0;i<n;i++)
	    cin>>A[i];
    	for(int i=0;i<n;i++)
    	{
	      for(int j=i+1;j<n;j++)
	     {
	            if(A[i]==A[j])
	            count++;
	        }
	    
	    if(major<count)
	    {
	        major=count;
	        ans=A[i];
	    }
	    count=1;
	}
	
	    if(major>n/2)
	       cout<<ans<<endl;
	    else
	        cout<<"NO Majority Element"<<endl;
	    t--;
	}
	return 0;
}
