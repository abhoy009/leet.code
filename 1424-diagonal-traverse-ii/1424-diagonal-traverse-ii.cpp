class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> diagonalMap;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                diagonalMap[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> result;

        for (const auto& pair : diagonalMap) {
            const vector<int>& diagonalElements = pair.second;
            result.insert(result.end(), diagonalElements.rbegin(), diagonalElements.rend());
        }

        return result;
    }
};