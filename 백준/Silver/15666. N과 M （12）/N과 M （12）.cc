#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
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
        arr[cnt] = v[i];
        dfs(cnt + 1, n, m, i);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();

    dfs(0, n, m, 0);

    return 0;
}