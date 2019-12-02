#include <iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int main() {
	int t,n,m,diff, temp;
	cin>>t;
	while(t--)
	{
	    cin>>n;
		diff = INT_MAX;
	    int A[n];
	    for(int i =0 ; i < n ; i++)
	        cin>>A[i];
        cin>>m;
        sort(A,A+n);
        
        for(int i = 0 ; i < n - m + 1; i++)
        {
            temp = A[i+m-1]  - A[i];
            if(temp < diff)
                diff = temp;
				
        }
	        cout<< diff;
			cout<< "\n";
	}
	return 0;
}