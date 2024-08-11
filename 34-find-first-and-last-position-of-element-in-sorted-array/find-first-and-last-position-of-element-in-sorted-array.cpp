class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> res = {-1, -1};

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) {
                res[0] = mid;
                r = mid - 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 0;
        r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) {
                res[1] = mid;
                l = mid + 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};