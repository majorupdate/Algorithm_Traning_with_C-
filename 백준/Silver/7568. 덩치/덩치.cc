#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector< tuple<int, int, int> > v;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        v.push_back(make_tuple(a, b, n));
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                // cout << i << " " << j << endl;
                if ((get<0>(v[i]) > get<0>(v[j])) && (get<1>(v[i]) > get<1>(v[j])))
                {
                    get<2>(v[i])--;
                }
                else if ((get<0>(v[i]) < get<0>(v[j])) && (get<1>(v[i]) < get<1>(v[j])))
                {
                    continue;
                }
                else if ((get<0>(v[i]) == get<0>(v[j])) && (get<1>(v[i]) == get<1>(v[j])))
                {
                    get<2>(v[i])--;
                }
                else
                {
                    get<2>(v[i])--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << get<2>(v[i]) << " ";
    }
    

    return 0;
}