class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int cmax = nums[0], gmax = nums[0];
        int cmin = nums[0], gmin = nums[0];
        int total = nums[0];

        for (int i = 1; i < n; i++) {
            cmax = max(nums[i], cmax + nums[i]);
            gmax = max(gmax, cmax);
            cmin = min(nums[i], cmin + nums[i]);
            gmin = min(gmin, cmin);
            total += nums[i];
        }
        if (gmax < 0) return gmax;

        return max(gmax, total - gmin);
    }
};
