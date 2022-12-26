#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n; cin >> n;

    string list;
    for (int i = 0; i < n; i++)
    {
        cin >> list;
        
        int cnt = 0;
        int sum = 0;
        int size = list.size();
        
        for (int i = 0; i < list.size(); i++)
        {
            char chr = list.at(i);
            if (chr == 'O')
            {
                cnt++;
            }
            else if (chr == 'X')
            {
                sum += (cnt + 1) * cnt / 2;
                cnt = 0;
            }
        }
        sum += (cnt + 1) * cnt / 2;

        cout << sum << endl;
    }
    
    return 0;    
}