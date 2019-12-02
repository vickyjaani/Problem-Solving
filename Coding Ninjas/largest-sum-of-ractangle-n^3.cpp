#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int **matrix = new int *[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    int max_sum = INT_MIN;
    int left = 0, right = 0, up = 0, down = 0;

    for (int sr = 0; sr < m; sr++)
    {
        int *sum = new int[n]{0};
        for (int er = sr; er < m; er++)
        {
            for (int j = 0; j < n; j++)
                sum[j] += matrix[er][j];

            int tempsum = sum[0];
            int templeft = 0;
            int tempright = 0;
            for (int col = 1; col < n; col++)
            {

                if (tempsum + sum[col] > sum[col])
                {
                    tempsum += sum[col];
                    tempright = col;
                }
                else
                {
                    tempsum = sum[col];
                    templeft = col;
                    tempright = col;
                }
                if (max_sum < tempsum)
                {
                    max_sum = tempsum;
                    up = sr;
                    down = er;
                    left = templeft;
                    right = tempright;
                }
            }
        }
        delete[] sum;
    }
    cout << max_sum;
    //cout<< " " << up << " " << down << " " << left << " " << right;
    for (int i = 0; i < m; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}