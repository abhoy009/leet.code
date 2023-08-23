class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1; // Discard left half
            } else if (nums[mid] < nums[right]) {
                right = mid; // Discard right half
            } else {
                // When nums[mid] and nums[right] are equal, we can't determine which side to discard
                // So, decrease the search space by moving right pointer to the left
                right--;
            }
        }

        return nums[left];
    }
};
