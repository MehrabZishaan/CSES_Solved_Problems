/// https://cses.fi/problemset/task/1094/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long moves = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            moves += (long long)(arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }

    printf("%lld\n", moves);

    return 0;
}
