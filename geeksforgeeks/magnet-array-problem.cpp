//https://practice.geeksforgeeks.org/problems/magnet-array-problem/0/?track=sp-arrays-and-searching&batchId=152
#include <iostream>
#include <iomanip>
#include <cmath>
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
        {
            double start = a[i - 1];
            double end = a[i];
            while (1)
            {
                double mid = (start + end) / 2;
                double f = 0;
                for (int j = 0; j < n; j++)
                    f += 1 / (mid - a[j]);
                if (abs(f) < 0.0000000000001)
                {
                    cout << fixed << setprecision(2) << mid << " ";
                    break;
                }
                else if (f > 0)
                    start = mid;
                else
                    end = mid;
            }
        }
        cout << "\n";
    }
    return 0;
}