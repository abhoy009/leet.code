class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowSet, colSet, subgridSet;

        for (int i = 0; i < 9; i++) {
            rowSet.clear();
            colSet.clear();

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && rowSet.count(board[i][j])) {
                    return false;
                }
                if (board[i][j] != '.') {
                    rowSet.insert(board[i][j]);
                }
                if (board[j][i] != '.' && colSet.count(board[j][i])) {
                    return false;
                }
                if (board[j][i] != '.') {
                    colSet.insert(board[j][i]);
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                subgridSet.clear();

                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] != '.' && subgridSet.count(board[x][y])) {
                            return false;
                        }
                        if (board[x][y] != '.') {
                            subgridSet.insert(board[x][y]);
                        }
                    }
                }
            }
        }

        return true;
    }
};
