#include <bits/stdc++.h>
using namespace std;
int minCost(int coin[], int n, int k)
{
    sort(coin, coin + n);
    int coins_needed = ceil(n / (k + 1));
    int ans = 0;
    for (int i = 0; i <= coins_needed - 1; i++)
    {
        ans += coin[i];
    }
    return ans;
}
int main()
{
    int coin[] = {8, 5, 3, 10, 2, 1, 15, 25};
    int k = 3;
    cout << minCost(coin, 8, k);
    return 0;
}
