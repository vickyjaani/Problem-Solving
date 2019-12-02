#include <iostream>
using namespace std;

#include <cmath>
int minCount(int n)
{

    int finalans = 1000;
    for (int i = sqrt(n); i > 0; i--)
    {
        int ans = 0;
        int k = i;
        int z = n;
        do
        {
            z = z - k * k;
            ans++;
            k = sqrt(z);
        } while (z > 0);

        if (z == 0)
            if (finalans > ans)
                finalans = ans;
    }
    return finalans;
}

int main()
{

    int num;
    cin >> num;
    cout << minCount(num);
}
