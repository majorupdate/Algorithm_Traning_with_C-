#include <iostream>
using namespace std;

int chess[15][15] = {0};
int ans = 0;

void queen(int i, int j, int cnt, int n)
{
    for (int a = i; a < n; a++)
    {
        if (chess[a][j] == 0)
        {
            chess[a][j] = cnt;
        }
    }
    for (int b = 0; b < n; b++)
    {
        if (chess[i][b] == 0)
        {
            chess[i][b] = cnt;
        }
    }
    int p = i, q = j;
    while (p < n && q >= 0)
    {
        if (chess[p][q] == 0)
        {
            chess[p][q] = cnt;
        }
        p++; q--;
    }
    p = i, q = j;
    while (p < n && q < n)
    {
        if (chess[p][q] == 0)
        {
            chess[p][q] = cnt;
        }
        p++; q++;
    }
}

void undo_queen(int i, int j, int cnt, int n)
{
    for (int a = i; a < n; a++)
    {
        if (chess[a][j] == cnt)
        {
            chess[a][j] = 0;
        }
    }
    for (int b = 0; b < n; b++)
    {
        if (chess[i][b] == cnt)
        {
            chess[i][b] = 0;
        }
    }
    int p = i, q = j;
    while (p < n && q >= 0)
    {
        if (chess[p][q] == cnt)
        {
            chess[p][q] = 0;
        }
        p++; q--;
    }
    p = i, q = j;
    while (p < n && q < n)
    {
        if (chess[p][q] == cnt)
        {
            chess[p][q] = 0;
        }
        p++; q++;
    }
}

void dfs(int a, int cnt, int n)
{
    if (cnt == n + 1)
    {
        ans++;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (chess[a][j] == 0)
        {
            queen(a, j, cnt, n);
            dfs(a + 1, cnt + 1, n);
            undo_queen(a, j, cnt, n);
        }
    }
}


int main()
{
    int n; cin >> n;
    
    dfs(0, 1, n);

    cout << ans;

    return 0;
}