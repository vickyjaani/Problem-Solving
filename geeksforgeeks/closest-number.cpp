#include <iostream>
using namespace std;

int findClosest(int a[], int start, int end, int k)
{
    int mid = (start + end) / 2;
    int next = mid + 1;
    while (a[mid] == a[next])
        next++;
    int prev = mid - 1;
    while (a[mid] == a[prev])
        prev--;

    if (mid == start)
        return (abs(a[mid] - k) < abs(a[mid + 1] - k)) ? a[mid] : a[mid + 1];

    if (abs(a[mid] - k) < abs(a[prev] - k) && abs(a[mid] - k) < abs(a[next] - k))
        return a[mid];
    if (abs(a[next] - k) == abs(a[prev] - k))
        return a[next];
    if (abs(a[next] - k) < abs(a[prev] - k))
        return findClosest(a, next - 1, end, k);
    else
        return findClosest(a, start, prev + 1, k);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = findClosest(a, 0, n - 1, k);
        cout << ans << endl;
    }
    return 0;
}