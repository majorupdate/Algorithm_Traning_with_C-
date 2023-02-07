#include <iostream>

using namespace std;

bool find(long long num)
{
    int cnt = 0;
    while (num > 0)
    {
        int temp = num % 10;
        if (temp == 6)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        
        if (cnt >= 3)
        {
            return true;
        }

        num /= 10;
    }
    
    return false;
}

int main()
{
    int n; cin >> n;
    
    int cnt = 0;
    long long num = 665;
    
    while (cnt != n)
    {
        num++;
        if (find(num) == true)
        {
            cnt++;
        }
    }
    
    cout << num--;
    
    return 0;
}