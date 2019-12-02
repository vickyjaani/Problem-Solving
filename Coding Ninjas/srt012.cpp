#include <iostream>
#include <algorithm>

using namespace std;

void sort012(int arr[], int n)
{
    int c0=0, c2 = n-1 ;
    for(int i =0 ; i<=c2 ; i++)
    {
        if(arr[i] == 0)
        {
            int temp = arr[i];
            arr[i] = arr[c0];
            arr[c0] = temp;
            c0++;
        }
        if(arr[i] == 2)
        {
            int temp = arr[i];
            arr[i] = arr[c2];
            arr[c2] = temp;
            c2--;
            i--;
        }
    }
    return;
}

int main() {

	int size_first;

	cin>>size_first;
	int *arr_first=new int[1+size_first];	
	
	for(int i=0;i<size_first;i++)
		cin>>arr_first[i];
	
	sort012(arr_first,size_first);
		
	for(int i=0;i<size_first;i++)
		cout<<arr_first[i]<<" ";	
	return 0;
}
