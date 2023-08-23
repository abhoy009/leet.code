class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cols(n, 0); // Store the column index of each queen in each row
        int count = 0;
        solveNQueens(n, 0, cols, count);
        return count;
    }
    
private:
    void solveNQueens(int n, int row, vector<int>& cols, int& count) {
        if (row == n) {
            count++;
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isValid(cols, row, col)) {
                cols[row] = col; // Place queen at (row, col)
                solveNQueens(n, row + 1, cols, count); // Move to the next row
                cols[row] = 0; // Backtrack
            }
        }
    }
    
    bool isValid(vector<int>& cols, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (cols[i] == col || abs(row - i) == abs(col - cols[i])) {
                return false; // Check column and diagonal conflicts
            }
        }
        return true;
    }
};
