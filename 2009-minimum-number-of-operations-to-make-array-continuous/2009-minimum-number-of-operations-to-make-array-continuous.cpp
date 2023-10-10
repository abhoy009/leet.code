class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            int right = upper_bound(nums.begin(), nums.end(), nums[i] + n - 1) - nums.begin();
            maxLen = max(maxLen, right - i);
        }

        return n - maxLen;
    }
};
