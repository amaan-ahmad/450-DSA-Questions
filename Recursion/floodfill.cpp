#include <iostream>
#include <vector>
#include <string>

/*
Sample input:

T1
----
3 3
0 0 0
1 0 1
0 0 0

T2
----
3 3
0 0 0
1 0 0
0 0 0

*/

using namespace std;

void floodfill(vector<vector<int>> maze, int sr, int sc, int dr, int dc, string asf, char lastMove, vector<vector<int>> vis)
{

    if (sr < 0 || sc < 0 || sr > dr || sc > dc)
    {
        // boundary crossed
        return;
    }
    else

        if (sr == dr && sc == dc)
    {
        cout << asf << endl;
        return;
    }
    else if (maze[sr][sc] == 1)
    {
        return;
    }
    else if (vis[sr][sc] == 1)
    {
        return;
    }

    vis[sr][sc] = 1;

    if (lastMove != 'd')
    {
        floodfill(maze, sr - 1, sc, dr, dc, asf + "t", 't', vis);
    }

    if (lastMove != 'r')
    {
        floodfill(maze, sr, sc - 1, dr, dc, asf + "l", 'l', vis);
    }

    if (lastMove != 't')
    {
        floodfill(maze, sr + 1, sc, dr, dc, asf + "d", 'd', vis);
    }

    if (lastMove != 'l')
    {
        floodfill(maze, sr, sc + 1, dr, dc, asf + "r", 'r', vis);
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    vector<vector<int>> vis(n, vector<int>(m));
    floodfill(arr, 0, 0, n - 1, m - 1, "", ' ', vis);
    return 0;
}