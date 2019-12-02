//https://practice.geeksforgeeks.org/problems/equilibrium-point/0/?ref=self

#include <iostream>
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

        int sumR = 0;
        for (int i = 2; i < n; i++)
        {
            sumR += a[i];
        }
        int sumL = a[0];
        for (int i = 1; i < n - 1; i++)
        {
            if (sumL == sumR)
            {
                cout << i + 1 << endl;
                break;
            }
            sumL += a[i];
            sumR -= a[i + 1];
        }
        if (n == 1)
        {
            cout << "1" << endl;
        }

        else if (sumL != sumR)
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}