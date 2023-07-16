/// Grid Paths using recursion and memoization
/// https://cses.fi/problemset/task/1638/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
int n;
char grid[1000][1000];
int dp[1000][1000];

int countPaths(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (grid[i][j] == '*')
        return 0;
    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int paths = 0;
    if (i - 1 >= 0)
    {
        paths += countPaths(i - 1, j);
        paths %= N;
    }
    if (j - 1 >= 0)
    {
        paths += countPaths(i, j - 1);
        paths %= N;
    }

    return dp[i][j] = paths;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << countPaths(n - 1, n - 1);

    return 0;
}
