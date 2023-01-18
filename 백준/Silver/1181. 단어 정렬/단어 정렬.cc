#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b)
{
    if (a.size() > b.size())
    {
        return false;
    }
    else if (a.size() < b.size())
    {
        return true;
    }
    else
    {
        if (a > b)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
}

int main()
{
    int n; cin >> n;
    vector<string> lst;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        string a; cin >> a;
        for (int j = 0; j < lst.size(); j++)
        {
            if (lst[j] == a)
            {
                flag = false;
            }
        }
        if (flag)
        {
            lst.push_back(a);
        }
    }
    
    sort(lst.begin(), lst.end(), compare);
    
    for (int i = 0; i <lst.size(); i++)
    {
        cout << lst[i] << "\n";
    }
    
    return 0;
}