#include <iostream>
#include <string>

using namespace std;

int main()
{
    int C; cin >> C;

    cout << fixed;
    cout.precision(3);
    
    while (C--)
    {
        double avg = 0;
        int N; cin >> N;
        int *arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            avg += arr[i]; 
        }
        avg /= N;
        
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (avg < arr[i])
            {
                cnt++;
            }
        }
        
        cout << (double) cnt / N * 100 << "%" << endl;
        delete[] arr;
    }
    
    return 0;    
}