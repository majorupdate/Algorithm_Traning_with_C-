#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int add(int i)
{
    int sum = i;
    while (i > 0)
    {
        sum += i % 10;
        i /= 10;
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;
    int min = n;

    for (int i = 1; i < n; i++)
    {
        if ((i < min) && (add(i) == n))
        {
            min = i;
            break;
        }
    }

    if (min == n)
    {
        cout << 0;
    }
    else
    {
        cout << min;
    }

    return 0;
}