#include <iostream>
using namespace std;

void explore(string keys[], int i, int nums[], int n,string word )
{
    
    if(i == n)
    {
        cout<< word <<" ";
        word = "";
        return ;
    }
    for( char x : keys[ (nums[i] - 2) ] )
    {
        
        
        explore(keys, i+1, nums,n,word+x);
        
        
    }
    
    
}

int main() {
    string keys[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int t,n;
    cin>>t;
    
	while(t--)
	{
	    cin>>n;
	    int A[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>A[i];
	    }
	    string mystr = "";
	    explore(keys,0,A,n,mystr);
	        
	}
	return 0;
}
