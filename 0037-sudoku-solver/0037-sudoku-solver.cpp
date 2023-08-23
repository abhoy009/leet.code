class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;
                            if (solve(board)) {
                                return true;
                            }
                            board[row][col] = '.'; // If the current num doesn't lead to a solution, backtrack
                        }
                    }
                    return false; // No valid number found for this cell
                }
            }
        }
        return true; // All cells filled successfully
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num || board[i][col] == num || board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num) {
                return false; // Check row, column, and the 3x3 subgrid for the same number
            }
        }
        return true;
    }
};
