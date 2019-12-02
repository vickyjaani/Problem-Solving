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
    int **sum = new int *[m];
    for (int i = 0; i < m; i++)
    {
        sum[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = 0;
            if (max_sum < matrix[i][j])
                max_sum = matrix[i][j];
            for (int k = i; k < m; k++)
            {
                for (int l = j; l < n; l++)
                {
                    sum[i][j] += matrix[k][l];
                }
            }
            if (max_sum < sum[i][j])
                max_sum = sum[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {

            for (int k = i; k < m; k++)
            {
                for (int l = j; l < n; l++)
                {
                    int tempsum = 0;
                    tempsum = sum[i][j];
                    if (k + 1 < m)
                        tempsum -= sum[k + 1][j];
                    if (l + 1 < n)
                        tempsum -= sum[i][l + 1];
                    if (k + 1 < m && l + 1 < n)
                        tempsum += sum[k + 1][l + 1];
                    if (max_sum < tempsum)
                        max_sum = tempsum;
                }
            }
        }
    }
    cout << max_sum;

    for (int i = 0; i < m; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    for (int i = 0; i < m; i++)
    {
        delete[] sum[i];
    }
    delete[] sum;
    return 0;
}
