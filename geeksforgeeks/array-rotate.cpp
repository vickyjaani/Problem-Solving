#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[200];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int d;
        cin >> d;
        queue<int> temp;

        for (int i = 0; i < n - d; i++)
        {
            if (i < d)
                temp.push(a[i]);
            a[i] = a[i + d];
        }
        for (int i = n - d; i < n; i++)
        {
            if (i < d)
                temp.push(a[i]);
            a[i] = temp.front();
            if (!temp.empty())
                temp.pop();
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}