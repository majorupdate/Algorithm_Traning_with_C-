#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool check[20] = {false};
int list_1[10] = {0};
int list_2[10] = {0};
int s[20][20] = {0};

vector<int> v;

void dfs(int cnt, int n, int a)
{
    if (cnt == n / 2)
    {
        int cnt_2 = 0;
        for (int i = 1; i < n; i++)
        {
            if (check[i] == false)
            {
                list_2[cnt_2++] = i;
            }
        }
        
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < cnt - 1; i++)
        {
            for (int j = i + 1; j < cnt; j++)
            {
                sum1 += (s[list_1[i]][list_1[j]] + s[list_1[j]][list_1[i]]);
                sum2 += (s[list_2[i]][list_2[j]] + s[list_2[j]][list_2[i]]);
            }
        }
        
        v.push_back(abs(sum1 - sum2));
        return;
    }

    for (int i = a; i < n; i++)
    {
        if (check[i] == true)
        {
            continue;
        }
        check[i] = true;
        list_1[cnt] = i;
        dfs(cnt + 1, n, i);
        check[i] = false;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    list_1[0] = 0;
    check[0] = true;
    dfs(1, n, 1);

    int min = *min_element(v.begin(), v.end());
    cout << min;

    return 0;
}