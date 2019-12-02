#include<iostream>
using namespace std;
int main()
 {
	int t ;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    for(int i = 0; i < n-1 ; i++)
	    {
	        if(i % 2 == 0)
	        {
	            for(int j = n-1 - (i/2) ; j >= i/2 + 1 ; j--)
	            {
	                if(a[j] > a[j-1])
	                {
	                    int temp = a[j];
	                    a[j] = a[j-1];
	                    a[j-1] = temp;
	                }
	            }
	        }
	        else
	        {
	            for(int j = 1 + i/2 ; j < n-1 - i / 2; j++)
	            {
	                if(a[j] > a[j+1])
	                {
	                    int temp = a[j];
	                    a[j] = a[j+1];
	                    a[j+1] = temp;
	                }
	            }
	        }
	    }
	    if(n % 2 == 1)
	    {
	        for(int i=0; i<n; i++)
	        {
	            cout << a[i] << " ";
	        }
	        cout << endl;
	    }
	    else
	    {
	        for(int i=n-1; i >=0; i--)
	        {
	            cout << a[i] << " ";
	        }
	        cout << endl;
	    }
	    
	}
	return 0;
}