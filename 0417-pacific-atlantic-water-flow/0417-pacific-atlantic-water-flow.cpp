class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> canReachPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> canReachAtlantic(rows, vector<bool>(cols, false));
        vector<vector<int>> result;
        
        // DFS to mark cells that can reach the Pacific
        for (int i = 0; i < rows; i++) {
            dfs(heights, canReachPacific, i, 0);
            dfs(heights, canReachAtlantic, i, cols - 1);
        }
        
        for (int j = 0; j < cols; j++) {
            dfs(heights, canReachPacific, 0, j);
            dfs(heights, canReachAtlantic, rows - 1, j);
        }
        
        // Check for cells that can reach both Pacific and Atlantic
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& canReach, int row, int col) {
        static const vector<int> directions = {-1, 0, 1, 0, -1};
        canReach[row][col] = true;
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i];
            int newCol = col + directions[i + 1];
            
            if (newRow >= 0 && newRow < heights.size() &&
                newCol >= 0 && newCol < heights[0].size() &&
                !canReach[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                dfs(heights, canReach, newRow, newCol);
            }
        }
    }
};
