#include <iostream>
#define MAX 51
using namespace std;

int compare(char (*chess)[MAX], char (*board)[MAX], int a, int b)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chess[a + i][b + j] != board[a + i][b + j])
            {
                cnt++;
            }
        }
    }

    return (cnt > 32) ? (64 - cnt) : (cnt);
}

int main()
{
    int N, M;
    cin >> N >> M;

    char chess[MAX][MAX];
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < M; j++)
            {
                (j % 2 == 0) ? (chess[i][j] = 'B') : (chess[i][j] = 'W');
            }
        }
        else
        {
            for (int j = 0; j < M; j++)
            {
                (j % 2 == 1) ? (chess[i][j] = 'B') : (chess[i][j] = 'W');
            }
        }
    }
    
    char board[MAX][MAX] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int min = 64;
    int temp = 0;
    for (int a = 0; a < N - 7; a++)
    {
        for (int b = 0; b < M - 7; b++)
        {
            temp = compare(chess, board, a, b);
            if (temp < min)
            {
                min = temp;
            }
        }
    }

    cout << min;

    return 0;
}