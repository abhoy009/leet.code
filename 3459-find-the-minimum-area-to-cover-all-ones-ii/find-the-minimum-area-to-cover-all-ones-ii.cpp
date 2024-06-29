class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int minSum ;

        for (int i = 0; i < n; ++i) {
            int val = minimumArea(grid, 0, i, 0, m - 1);
            if(i+1 > n-1)continue;
            int new_val = val + find(grid, i + 1, n-1, 0, m - 1);
            minSum = min(minSum, new_val);
        }
        
        for(int i=n-1; i>=0; --i){
            int val = minimumArea(grid,i,n-1, 0, m - 1);
            if(i-1 < 0)continue;
            int new_val = val + find(grid, 0, i-1, 0, m - 1);
            minSum = min(minSum, new_val);
        }
        

        for (int i = 0; i < m; ++i) {
            int val = minimumArea(grid, 0, n - 1, 0, i);
            if(i+1>=m)continue;
            int new_val = val + find(grid, 0, n - 1, i + 1, m-1);
            minSum = min(minSum, new_val);
        }
        
        for(int i=m-1; i>0; --i){
            int val = minimumArea(grid, 0, n - 1, i, m-1);
            int new_val = val + find(grid, 0, n - 1,0, i-1);
            minSum = min(minSum, new_val);
        }
        return minSum;
    }

    int find(vector<vector<int>>& g, int i1, int i2, int j1, int j2) {
        int r1 = -1, r2 = -1, c1 = -1, c2 = -1;

        for (int i = i1; i <= i2; ++i) {
            for (int j = j1; j <= j2; ++j) {
                if (g[i][j]) {
                    if (r1 == -1) {
                        r1 = i;
                        r2 = i;
                    } else {
                        r2 = i;
                    }
                }
            }
        }

        for (int j = j1; j <= j2; ++j) {
            for (int i = i1; i <= i2; ++i) {
                if (g[i][j]) {
                    if (c1 == -1) {
                        c1 = j;
                        c2 = j;
                    } else {
                        c2 = j;
                    }
                }
            }
        }

        if (min(r1, r2) == -1) {
            return 0;
        }

        int res = INT_MAX;
        for (int i = r1; i <= r2; ++i) {
            int val = minimumArea(g, r1, i, c1, c2);
            if (i + 1 <= r2) val += minimumArea(g, i + 1, r2, c1, c2);
            res = min(res, val);
        }
        for (int j = c1; j <= c2; ++j) {
            int val = minimumArea(g, r1, r2, c1, j);
            if (j + 1 <= c2) val += minimumArea(g, r1, r2, j + 1, c2);
            res = min(res, val);
        }
        return res;
    }

    int minimumArea(vector<vector<int>>& g, int i1, int i2, int j1, int j2) {
        int r1 = -1, r2 = -1, c1 = -1, c2 = -1;

        for (int i = i1; i <= i2; ++i) {
            for (int j = j1; j <= j2; ++j) {
                if (g[i][j]) {
                    if (r1 == -1) {
                        r1 = i;
                        r2 = i;
                    } else {
                        r2 = i;
                    }
                }
            }
        }

        for (int j = j1; j <= j2; ++j) {
            for (int i = i1; i <= i2; ++i) {
                if (g[i][j]) {
                    if (c1 == -1) {
                        c1 = j;
                        c2 = j;
                    } else {
                        c2 = j;
                    }
                }
            }
        }

        if (min(r1, r2) == -1) {
            return 0;
        }

        int l = r2 - r1 + 1;
        int w = c2 - c1 + 1;
        return l * w;
    }
};