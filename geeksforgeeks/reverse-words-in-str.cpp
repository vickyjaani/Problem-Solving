//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0/?track=sp-strings&batchId=152
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string next;
    getline(cin, next);
    while (t--)
    {
        string s;
        getline(cin, s);
        string str;
        stack<string> mystack;
        int i = 0, j = 0;
        while (s[i] != '\0')
        {
            if (s[i] == '.')
            {
                str = s.substr(i - j, j);
                mystack.push(str);
                mystack.push(".");
                j = 0;
            }
            else
            {
                j++;
            }
            i++;
        }
        mystack.push(s.substr(i - j, j));
        while (!mystack.empty())
        {
            cout << mystack.top();
            mystack.pop();
        }
        cout << endl;
    }
    return 0;
}