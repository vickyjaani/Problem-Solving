#include <iostream>
using namespace std;
long maxPathSum(int ar1[], int ar2[], int m, int n)
{
    int i = 0, j = 0, s1 = 0, s2 = 0;
    long res = 0;
    while(i<m && j<n)
    {   
        if(ar1[i] < ar2[j] )
        {
            s1 += ar1[i];
            i++;
        }
        else if(ar1[i] > ar2[j])
        {
            s2 += ar2[j];
            j++; 
        }
        else
        {
            res += max(s1,s2);
            s1 = 0;
            s2 = 0;
            while(ar1[i] == ar2[j])
            {
                res += ar1[i];                
                i++;
                j++;             
            }
        }       
    }
    if(i == m)
        {
            
            while(j<n)
            {
                res += ar2[j];
                j++;
            }
        }
        else
        {
            
            while(i<m)
            {
                res += ar1[i];
                cout<<endl<<i<<endl;
                i++;
            }
        }
    return res;
}

int main() {
    int *a,*b,m,n,i;
    cin>>m;
    a=new int[m];
    for(i=0;i<m;i++)
        cin>>a[i];
    cin>>n;
    b=new int[n];
    for(i=0;i<n;i++)
        cin>>b[i];
    long ans = maxPathSum(a,b,m, n);
    cout << ans << endl;
    delete a;
    delete b;
    return 0;
}