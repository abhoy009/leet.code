class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> newBoard = board; 
        
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;
                
                for (const pair<int, int>& dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1) {
                        liveNeighbors++;
                    }
                }
                
                if (board[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        newBoard[i][j] = 0; 
                    }
                } else {
                    if (liveNeighbors == 3) {
                        newBoard[i][j] = 1; 
                    }
                }
            }
        }
        
        board = newBoard;
    }
};
