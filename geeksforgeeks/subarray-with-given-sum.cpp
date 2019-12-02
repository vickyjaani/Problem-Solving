// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0/?track=sp-arrays-and-searching&batchId=152

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int si = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            while (sum > s)
            {
                sum -= a[si];
                si++;
            }
            if (sum == s)
            {
                cout << si + 1 << " " << i + 1 << endl;
                break;
            }
        }
        if (sum != s)
            cout << "-1" << endl;
    }
    return 0;
}