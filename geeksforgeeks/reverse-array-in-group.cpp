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
        int m = 1;
        for (; m * k < n; m++)
            for (int i = m * k - 1; i >= (m - 1) * k; i--)
            {
                cout << a[i] << " ";
            }
        if ((m - 1) * k < n)
            for (int i = n - 1; i >= (m - 1) * k; i--)
                cout << a[i] << " ";

        cout << endl;
    }
    return 0;
}