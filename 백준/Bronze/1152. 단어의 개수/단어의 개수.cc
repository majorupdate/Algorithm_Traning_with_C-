#include <iostream>

using namespace std;

int main()
{
    string a; getline(cin, a);
    int cnt = 0;
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (a[i] == ' ')
        {
            cnt++;
        }
    }
    cnt++;
    
    if (a == " ")
    {
        cout << 0;
    }
    else
    {
        cout << cnt;
    }
    
    return 0;
}