#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> arr;
int list[8] = {0};

void dfs(int cnt, int n, int m)
{
    if (cnt == m)
    {
        v.push_back(arr);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        arr.push_back(list[i]);
        dfs(cnt + 1, n, m);
        arr.pop_back();
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

    dfs(0, n, m);
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}