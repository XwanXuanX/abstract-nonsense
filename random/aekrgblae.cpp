// Given a list containing n-1 random unique numbers from [1 .. n] inclusive, find the missing number.

// Example 1:
// Input: lst = {9,2,10,6,7,4,8,1,3}, len = 9
// Output: 5

#include <vector>
using namespace std;

int main(int *lst, int len)
{
    vector<int> input(len);
    for (int i = 0; i < len; ++i) {
        input[lst[i]];
    }

    // vector<int> lst = {9,2,10,6,7,4,8,1,3};
    vector<int> sorted(input.size() + 1, -1);

    for (int i = 0; i < input.size(); ++i) {
        sorted[lst[i]] = 1;
    }
    for (int i = 1; i <= input.size(); ++i) {
        if (sorted[i] == -1) {
            return i;
        }
    }
}

// Given an m x n 2D binary grid which represents a map of 1s (land) and 0s (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// Input:
// int h = 4;
// int w = 5;
// int grid[h][w] = {
// {1,1,1,1,0},
// {1,1,0,1,0},
// {1,1,0,0,0},
// {0,0,0,0,0}
// };
// Output: 1

// Example 2:
// Input:
// int h = 4;
// int w = 5;
// int grid[h][w] = {
// {1,1,0,0,0},
// {1,1,0,0,0},
// {0,0,1,0,0},
// {0,0,0,1,1}
// };
// Output: 3

#include <functional>

int main(int **grid, int h, int w)
{
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    vector<vector<bool>> vis(h, vector<bool>(w));

    function<void(int i, int j)> dfs;
    dfs = [&](int i, int j) {
        vis[i][j] = true;
        for (int k= 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || vis[ni][nj] || !grid[ni][nj]) {
                continue;
            }
            dfs(ni, nj);
        }
    };

    int comp = 0;
    for (int i = 0; i < h; ++i)  {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] && !vis[i][j]) {
                dfs(i, j);
                comp++;
            }
        }
    }
    // cout << comp;
}