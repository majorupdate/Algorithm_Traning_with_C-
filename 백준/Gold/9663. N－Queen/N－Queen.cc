#include <iostream>
#include <cmath>
using namespace std;

int chess[15] = {0};
int ans = 0;

bool check(int row_check, int n)
{
    for (int row = 0; row < row_check; row++)
    {
        if ((chess[row_check] == chess[row]) || (row_check - row) == abs(chess[row_check] - chess[row]))
        {
            return false;
        }
    }

    return true;
}

void dfs(int row, int n)
{
    if (row == n)
    {
        ans++;
        return;
    }

    for (int col = 1; col <= n; col++)
    {
        chess[row] = col;
        if (check(row, n) == true)
        {
            dfs(row + 1, n);
        }
    }
}


int main()
{
    int n; cin >> n;
    
    dfs(0, n);

    cout << ans;

    return 0;
}