//https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0/?track=sp-arrays-and-searching&batchId=152
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];

        int flag = 0;
        int i = 0;
        for (; i < s[0].length(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[0][i] != s[j][i] || s[j][i] == '\0')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
            cout << s[0][i];
        }
        if (i == 0)
            cout << "-1";

        cout << endl;
    }
    return 0;
}