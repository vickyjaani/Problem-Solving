//https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/1/?track=sp-arrays-and-searching&batchId=152

#include <bits/stdc++.h>
using namespace std;
int findExtra(int a[], int b[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        cout << findExtra(a, b, n) << endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below*/
int helper(int a[], int b[], int s, int e)
{
    int mid = (s + e) / 2;
    if (mid == s)
    {
        return (a[mid] == b[mid]) ? e : mid;
    }
    if (a[mid] == b[mid])
        return helper(a, b, mid, e);
    else
        return helper(a, b, s, mid);
}

int findExtra(int a[], int b[], int n)
{
    if (a[n - 2] == b[n - 2])
        return n - 1;
    return helper(a, b, 0, n - 2);
}