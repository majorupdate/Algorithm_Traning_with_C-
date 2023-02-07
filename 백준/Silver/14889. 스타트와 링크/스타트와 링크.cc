#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool check[10] = {false};
int s[20][20] = {0};

int ans = 1000000000;

void dfs(int cnt, int n, int a)
{
    if (cnt == n / 2)
    {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i] == true && check[j] == true)
                {
                    sum1 += s[i][j];
                }
                if (check[i] == false && check[j] == false)
                {
                    sum2 += s[i][j];
                }
            }
        }

        ans = min(ans, abs(sum1 - sum2));
    }

    for (int i = a; i < n; i++)
    {
        if (check[i] == true)
        {
            continue;
        }
        check[i] = true;
        dfs(cnt + 1, n, i + 1);
        check[i] = false;
    }
}

int main()
{
    int n; cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }
    
    dfs(0, n, 0);
    
    cout << ans;

    return 0;
}