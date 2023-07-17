/// https://cses.fi/problemset/task/1083/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    // Calculate the expected sum of numbers from 1 to n
    long long expected_sum = ((long long)n * (n + 1)) / 2;

    // Calculate the actual sum of the given n-1 numbers
    long long actual_sum = 0;
    for (int i = 1; i < n; i++)
    {
        long long num;
        scanf("%lld", &num);
        actual_sum += num;
    }

    // Calculate the missing number
    long long missing_number = expected_sum - actual_sum;

    // Print the missing number
    printf("%lld\n", missing_number);

    return 0;
}
