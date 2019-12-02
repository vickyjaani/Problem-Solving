// https://practice.geeksforgeeks.org/problems/sort-in-specific-order/0/?track=sp-arrays-and-searching&batchId=152

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int j = 0, k = n - 1;
        for (int i = 0; i < n; i++)
        {
            int l;
            cin >> l;
            if (l % 2 == 0)
            {
                a[k] = l;
                k--;
            }
            else
            {
                a[j] = l;
                j++;
            }
        }

        sort(a + j, a + n);
        sort(a, a + j, greater<int>());
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }
    return 0;
}