#include <iostream>
using namespace std;

int numofAP(int *arr, int N)
{
    int AP[N][N][2] = {0};

    for (int i = 1; i < N; i++)
    {
        AP[0][i][0] = arr[i] - arr[0];
        AP[0][i][1] = 1;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            AP[i][j][0] = arr[j] - arr[i];
            int count = 1;
            for (int k = 0; k < i; k++)
            {
                if (arr[j] - arr[i] == AP[k][i][0])
                    count = (count + AP[k][i][1]) % 100001;
            }
            AP[i][j][1] = count;
        }
    }
    int ans = N + 1;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            ans = (ans + AP[i][j][1]) % 100001;
        }
    }
    return ans;
}

int main()
{

    int N;
    cin >> N;

    int *arr = new int[N + 1];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;

    return 0;
}
