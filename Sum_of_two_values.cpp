/// https://cses.fi/problemset/task/1640
/// Sorting and Searching
/// Sum of Two Values

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numElements, targetSum;
    cin >> numElements >> targetSum;
    vector<pair<int, int>>elements(numElements);

    for(int i=0; i < numElements; i++)
    {
        cin >> elements[i].first;
        elements[i].second = i+1;
    }

    sort(elements.begin(), elements.end());

    int leftIndex=0, rightIndex=numElements - 1;

    while(leftIndex < rightIndex)
    {
        int currentSum = elements[leftIndex].first + elements[rightIndex].first;

        if(currentSum < targetSum)
        {
            leftIndex++;
        }
        else if(currentSum > targetSum)
        {
            rightIndex--;
        }
        else
        {
            cout << elements[rightIndex].second << " " << elements[leftIndex].second << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << "\n";
    return 0;
}
