#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    else
    {
        return a.length() < b.length();
    }
}

int main()
{
    vector<string> lst;
    
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a; cin >> a;
        lst.push_back(a);
    }
    
    sort(lst.begin(), lst.end(), compare);
    
    for (int i = 0; i < lst.size(); i++)
    {
        if ((i == lst.size() - 1) || (lst[i] != lst[i + 1]))
            cout << lst[i] << '\n';
    }
    
    return 0;
}