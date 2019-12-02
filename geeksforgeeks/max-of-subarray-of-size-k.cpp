//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0/?track=sp-arrays-and-searching&batchId=152
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int max = a[0];
        for (int i = 1; i < k; i++)
        {
            if (max < a[i])
                max = a[i];
        }
        cout << max << " ";
        for (int i = k; i < n; i++)
        {
            if (max != a[i - k])
            {
                if (max < a[i])
                    max = a[i];
            }
            else
            {
                max = a[i];
                for (int j = i; j > i - k; j--)
                    if (max < a[j])
                        max = a[j];
            }
            cout << max << " ";
        }
        cout << endl;
    }
    return 0;
}