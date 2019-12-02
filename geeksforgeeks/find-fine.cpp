//https://practice.geeksforgeeks.org/problems/find-the-fine/0/?track=sp-arrays-and-searching&batchId=152
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        int p[n], c[n];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        int fine = 0;
        int flag = d % 2;
        for (int i = 0; i < n; i++)
            if (c[i] % 2 != flag)
                fine += p[i];

        cout << fine << endl;
    }
    return 0;
}