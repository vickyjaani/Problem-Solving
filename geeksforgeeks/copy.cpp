#include<iostream>
using namespace std;

int main() {
	//code
	int i,T,n;
	cin >> T;
	for(i=1;i<=T;i++)
	    {
	        int N;
	        cin >> N;
	        int arr[N];
	        for(n=0;n<N;n++)
	        {
	            cin >> arr[n];
	        }
	        int count = 1;
	        int l;
	        n = sizeof(arr)/sizeof(arr[0]);
	        while(count<N)
	        {
	            int last = arr[n-1];
	            for(int k=1;k<n;k++)
	            {
	                arr[n-k] = arr[n-k-1];
	            }
	            arr[0] = last;
	            if(count>1)
	            {
	                for(l=n-count;l<n-1;l++)
	                {   
	                    arr[l] = arr[l+1];
	                }
	                n = n - 1;
	            }
	            else
	            {
	                n = n - 1;
	            }
	            count++;
	        }
	        cout << arr[0] << "\n";
	    }
	return 0;
}
