#include <cmath>
#include <iostream>
#include <map>
using namespace std;


int max(int arr[], int n) 
{
	for(int i=0 ; i<n ; i++)
    {
        if(arr[i] == 0)
            arr[i] = -1;
    }
    map<int, int > mymap;
    int sum = 0;
    int max_length = 0;
    mymap[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(mymap[sum] > 0 && max_length < (i - mymap[sum] + 2))
            max_length = (i - mymap[sum] + 2);
        else
            mymap[sum] = i+2;
    }
    
    return max_length;
}


int main() {
    	int n=0;
    	cin>>n;
    	int *arr = new int[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	
    	cout << max(arr,n);
    	
	
}
