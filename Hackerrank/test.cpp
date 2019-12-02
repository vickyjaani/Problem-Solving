#include <bits/stdc++.h>
using namespace std;

void helper(stack<int> &s, int bottom)
{
    if (s.empty())
    {
        s.push(bottom);
        return;
    }
    int upr = s.top();
    s.pop();
    helper(s, bottom);
    s.push(upr);
    return;
}

void reverse(stack<int> &s)
{

    int bottom = s.top();
    s.pop();
    if (!s.empty())
        reverse(s);
    helper(s, bottom);
    return;
}

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        s.push(k);
    }
    reverse(s);
    for (int i = 0; i < n; i++)
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}