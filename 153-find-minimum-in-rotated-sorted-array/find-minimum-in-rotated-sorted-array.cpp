class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (nums[l] <= nums[r]) return nums[l];

            int mid = l + (r - l) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if ((nums[mid] <= nums[next]) && (nums[mid] <= nums[prev])) {
                return nums[mid];
            }
            if (nums[l] <= nums[mid]) {
                l = mid + 1;
            } else if (nums[mid] <= nums[r]) {
                r = mid - 1;
            }
        }
        return nums[l];
    }
};