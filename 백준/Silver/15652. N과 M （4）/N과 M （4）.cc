#include <iostream>
using namespace std;

int list[8] = {0};

void dfs(int cnt, int n, int m, int a)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << list[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = a; i <= n; i++)
    {
        list[cnt] = i;
        dfs(cnt + 1, n, m, i);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    dfs(0, n, m, 1);

    return 0;
}