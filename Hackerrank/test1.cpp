#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int getDist(int a, int b, int n, int **dist, int visited[])
{
    if (dist[a - 1][b - 1] != 0)
        return dist[a - 1][b - 1];

    visited[a - 1] = 1;
    for (int i = 0; i < n; i++)
    {
        if (dist[a - 1][i] != 0 && visited[i] == 0)
        {
            int temp_dist = getDist(i + 1, b, n, dist, visited);
            if (temp_dist != 0)
            {
                dist[a - 1][b - 1] = 1 + temp_dist;
                dist[b - 1][a - 1] = 1 + temp_dist;
                return dist[a - 1][b - 1];
            }
        }
    }
    return 0;
}
int main()
{
    int n, q;
    cin >> n >> q;
    int **dist = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = 0;
        }
    }
    int t = n;
    while (--t)
    {
        int p1, p2;
        cin >> p1 >> p2;
        dist[p1 - 1][p2 - 1] = 1;
        dist[p2 - 1][p1 - 1] = 1;
    }
    while (q--)
    {
        int num;
        cin >> num;
        int nodesGiven[num];
        for (int i = 0; i < num; i++)
            cin >> nodesGiven[i];
        int sum = 0;
        for (int i = 0; i < num - 1; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                int visited[n];
                memset(visited, 0, sizeof(visited));
                int dist1 = getDist(nodesGiven[i], nodesGiven[j], n, dist, visited);
                sum = (sum + ((nodesGiven[i] * nodesGiven[j]) % mod * dist1) % mod) % mod;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
