#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(pair<int, char> a, pair<int, char> b)
{
    return a.first > b.first;
}

int main(void)
{
    string a; cin >> a;
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    
    vector<pair<int, char>> b;
    for (int i = 0; i < 26; i++)
    {
        b.push_back(make_pair(0, (char) i + 'A'));
    }
    
    for (int i = 0; i < a.size(); i++)
    {
        (b[a[i] - 'A'].first)++;
    }
    
    sort(b.begin(), b.end(), compare);
    
    if (b[0].first == b[1].first)
    {
        cout << '?';
    }
    else
    {
        cout << b[0].second;
    }
    
    return 0;
}