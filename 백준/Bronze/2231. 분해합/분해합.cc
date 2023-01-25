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
    int n; cin >> n;
    int *arr = new int[n];
    int min = n;
    
    for (int i = 1; i < n; i++)
    {
        int temp = i;
        while (temp <= n)
        {
            if(arr[temp] == 1)
            {
                break;
            }
            int temp_next = add(temp);
            if (temp < min && temp_next == n)
            {
                min = temp;
                break;
            }
            arr[temp] = 1;
            temp = temp_next;
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