//https://practice.geeksforgeeks.org/problems/c-program-to-remove-consonants-from-a-string/0/?track=sp-arrays-and-searching&batchId=152
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string nextline;
    getline(cin, nextline);
    while (t--)
    {
        string s;
        getline(cin, s);
        int flag = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == ' ')
            {
                cout << s[i];
                flag = 1;
            }
        }
        if (flag == 0)
            cout << "No Vowel";
        cout << endl;
    }
    return 0;
}