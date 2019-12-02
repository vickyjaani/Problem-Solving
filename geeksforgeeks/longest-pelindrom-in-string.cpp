//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0/?track=sp-strings&batchId=152

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int i = 0;
        int max_l = 1;
        int s_i = 0;
        while (s[i] != '\0')
        {
            int j = 1;
            int temp_l = 1;
            while (s[i - j] == s[i + j] && j < i + 1 && s[i + j] != '\0')
            {
                temp_l += 2;
                j++;
            }
            if (max_l < temp_l)
            {
                max_l = temp_l;
                s_i = i - j + 1;
            }
            if (s[i] == s[i + 1])
            {
                j = 1;
                temp_l = 2;
                while (s[i - j] == s[i + 1 + j])
                {
                    temp_l += 2;
                    j++;
                }
            }
            if (max_l < temp_l)
            {
                max_l = temp_l;
                s_i = i - j + 1;
            }
            i++;
        }
        for (i = 0; i < max_l; i++)
        {
            cout << s[s_i];
            s_i++;
        }
        cout << endl;
    }
    return 0;
}