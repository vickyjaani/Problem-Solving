//https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0/?track=sp-arrays-and-searching&batchId=152
#include <bits/stdc++.h>
using namespace std;

void isPythagorean(int a[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] * a[i] + a[j] * a[j] == a[k] * a[k])
                {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        isPythagorean(a, n);
    }
    return 0;
}