#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX 1000

int h, w;
vector<vector<int>> MEMO(MAX, vector<int>(MAX, -1));

int getPaths(vector<vector<char>>& grid, int x, int y) {
    if (x == h - 1 && y == w - 1) {
        return 1;
    }
    if (MEMO[x][y] != -1) {
        return MEMO[x][y];
    }

    int paths = 0;

    if (x + 1 < h && grid[x + 1][y] != '#') {
        paths += getPaths(grid, x + 1, y);
    }
    if (y + 1 < w && grid[x][y + 1] != '#') {
        paths += getPaths(grid, x, y + 1);
    }

    MEMO[x][y] = paths % MOD;

    return MEMO[x][y];
}

int main() {
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];

    cout << getPaths(grid, 0, 0) << endl;

    return EXIT_SUCCESS;
}