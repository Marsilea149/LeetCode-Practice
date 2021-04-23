// credit to Huahua: https://www.youtube.com/watch?v=XSmgFKe-XYU

/** Difficulty 6/10
 *  Algorithm: DFS 
 *  Key: process all the neighbors until they all become '0', 
 *       when start a new island process, increment the count.
 */

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int y = 0; y < m; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                ans += grid[y][x] - '0';
                dfs(grid, y, x, m, n);
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<char>> &grid, int y, int x, int m, int n)
    {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0')
            return;

        grid[y][x] = '0';
        dfs(grid, y + 1, x, m, n);
        dfs(grid, y - 1, x, m, n);
        dfs(grid, y, x + 1, m, n);
        dfs(grid, y, x - 1, m, n);
    }
};