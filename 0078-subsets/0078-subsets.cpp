class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(nums, 0, current, result);
        return result;
    }

private:
    void generateSubsets(const vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        generateSubsets(nums, index + 1, current, result);

        current.push_back(nums[index]);
        generateSubsets(nums, index + 1, current, result);

        current.pop_back();
    }
};
