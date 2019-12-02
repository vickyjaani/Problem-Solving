#include <iostream>
#include <string>
using namespace std;

string solve(int n, int x, int y)
{
    string ans[n + 1];
    for (int i = 1; i <= n; i++)
    {

        if (i < x)
        {
            if (i % 2 == 1)
                ans[i] = "Beerus";
            else
                ans[i] = "Whis";
        }
        if (i == x)
            ans[i] = "Beerus";
        if (i > x && i < y)
        {
            if (ans[i - 1] == "Whis" || ans[i - x] == "Whis")
                ans[i] = "Beerus";
            else
                ans[i] = "Whis";
        }
        if (i == y)
            ans[i] = "Beerus";
        if (i > y)
        {
            if (ans[i - 1] == "Whis" || ans[i - x] == "Whis" || ans[i - y] == "Whis")
                ans[i] = "Beerus";
            else
                ans[i] = "Whis";
        }
    }

    return ans[n];
}
int n, x, y;
int main()
{
    cin >> n >> x >> y;
    cout << solve(n, x, y) << endl;
}