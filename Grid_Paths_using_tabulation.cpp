/// https://cses.fi/problemset/task/1638/
/// Grid Paths using tabulation
#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    char grid[n][n];


    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> grid[i][j];


    int dp[n][n];
    memset(dp, 0, sizeof(dp));


    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (grid[i][j] == '*')
                continue;
            if (i==0 && j==0)
                dp[i][j] = 1;


            if (i - 1 >= 0)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= N;
            }
            if (j-1 >= 0)
            {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= N;
            }
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}
