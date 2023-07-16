/// https://cses.fi/problemset/task/1745
/// Money sums using tabulation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numCoins;
    cin >> numCoins;
    vector<int> coins(numCoins);
    int totalSum = 0;

    for(int i=0; i<numCoins; i++)
    {
        cin >> coins[i];
        totalSum += coins[i];
    }

    vector<int>dp(totalSum + 1, 0);
    dp[0] = 1;

    for(int coin : coins)
    {
        for(int currentSum = totalSum; currentSum >= 0; currentSum--)
        {
            if(dp[currentSum] && currentSum + coin <= totalSum)
                dp[currentSum + coin] = 1;
        }
    }

    int count = 0;
    for(int i=1; i<=totalSum; i++)
        count += dp[i];

    cout << count << "\n";

    for(int i=1; i<=totalSum; i++)
    {
        if (dp[i])
            cout << i << " ";
    }

    return 0;
}
