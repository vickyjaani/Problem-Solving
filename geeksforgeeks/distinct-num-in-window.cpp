////https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/?track=sp-arrays-and-searching&batchId=152
#include <bits/stdc++.h>
using namespace std;
void countDistinct(int[], int, int);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        countDistinct(a, k, n);
        cout << endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{
    set<int> window;
    for (int i = 0; i < k; i++)
        window.insert(A[i]);
    cout << window.size() << " ";
    if (n == k)
        return;
    countDistinct(A + 1, k, n - 1);
}