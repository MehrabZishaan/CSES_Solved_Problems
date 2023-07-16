/// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum;
    cin >> n >> sum;

    int* coins = new int[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int* dp = new int[sum + 1]();
    dp[0] = 1;

    for (int i = 0; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + coins[j] <= sum)
                dp[i + coins[j]] = (dp[i + coins[j]] + dp[i]) % N;
        }
    }

    cout << dp[sum] << "\n";

    delete[] coins;
    delete[] dp;

    return 0;
}
