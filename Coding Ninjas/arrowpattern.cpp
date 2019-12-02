#include<iostream>

using namespace std;

int main()
{
    int n,i,j,k;
    cin >> n;
    for(i=1 ; i<n/2+1 ; i++)
    {
        for( j=1 ; j<i ; j++)
            cout<< " ";
        for( k=0 ; k<i ; k++)
            cout<< "*";
        j = n-i-j+1;
        while(j--)
            cout<< " ";
        cout<<endl;
    }

    for( i=n/2+1 ; i<=n ; i++)
    {
        for( j=0 ; j<n-i ; j++)
            cout<< " ";
        for( k=0 ; k<=n-i ; k++)
            cout<< "*";

        j = n-i+1;
        while(j--)
            cout<< " ";
        cout<<endl;
    }
}