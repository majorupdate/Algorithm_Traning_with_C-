#include <iostream>
#include <algorithm>

using namespace std;

int list[8] = {0};
int arr[8] = {0};

void dfs(int cnt, int n, int m, int a)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = a; i < n; i++)
    {
        arr[cnt] = list[i];
        dfs(cnt + 1, n, m, i);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    sort(list, list + n);
    
    dfs(0, n, m, 0);

    return 0;
}