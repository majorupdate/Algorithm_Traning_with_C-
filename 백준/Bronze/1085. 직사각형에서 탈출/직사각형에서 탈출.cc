#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h; cin >> x >> y >> w >> h;
    
    int min_x = ((w - x) > x) ? (x) : (w - x);
    int min_y = ((h - y) > y) ? (y) : (h - y);
    
    cout << ((min_x > min_y) ? (min_y) : (min_x));

    return 0;
}