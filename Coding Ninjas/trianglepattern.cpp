#include<iostream>

using namespace std;

int main()
{
    int n,i,j,k,l;
    cin>> n;
    for(i=1 ; i<=n ;i++)
    {

        for(j=0 ; j<n-i ; j++)
            cout << " ";

        for(k=i ; k<2*i ; k++)
            cout << k;

        for(l=k-2 ; l>=i ; l--)
            cout << l;

        cout << endl;
    }
    return 0;
}