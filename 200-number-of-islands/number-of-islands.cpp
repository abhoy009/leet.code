class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        // Mark current land as visited
        grid[i][j] = '0';
        
        // Explore adjacent lands
        dfs(grid, i+1, j);  // Down
        dfs(grid, i-1, j);  // Up
        dfs(grid, i, j+1);  // Right
        dfs(grid, i, j-1);  // Left
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
};