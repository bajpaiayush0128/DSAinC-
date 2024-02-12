#include <iostream>
using namespace std;

static int N;
static int maze[5][5];
static int sol[5][5];

bool isSafe(int i, int j)
{
    return (i < N && j < N && maze[i][j] == 1);
}

bool solveMazeRec(int i, int j)
{
    if (i == N - 1 && j == N - 1)
    {
        sol[i][j] = 1;
        return true;
    }
    if (isSafe(i, j))
    {
        sol[i][j] = 1;
        if (solveMazeRec(i + 1, j))
            return true;
        else if (solveMazeRec(i, j + 1))
            return true;
        sol[i][j] = 0;
    }
    return false;
}

bool solveMaze()
{
    if (!solveMazeRec(0, 0))
        return false;
    else
    {
        cout << sol[0][1];
        return true;
    }
}

int main()
{

    return 0;
}