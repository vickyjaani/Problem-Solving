#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int k;
    if(n%2 == 0)
        k = n-1;
    else
        k = n;
        
    for(int i=0 ; i<k ; i=i+2)
    {
        for(int j=0 ; j<n ; j++)
        {
            cout << (i*n)+j+1 << " ";
        }
        cout<<"\n";
    }

    if(n%2 == 0)
        k = n-1;
    else
        k = n-2;

    for(int i=k ; i>0 ; i=i-2)
    {
        for(int j=0 ; j<n ; j++)
        {
            cout << (i*n)+j+1 << " ";
        }
        cout<<"\n";
    }
    return 0;
}