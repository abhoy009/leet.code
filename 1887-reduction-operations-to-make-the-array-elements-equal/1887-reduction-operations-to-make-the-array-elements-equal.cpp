class Solution {
public:
    int reductionOperations(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>()); // Sort the array in descending order
        int operations = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < prev) {
                operations += i;
                prev = nums[i];
            }
        }

        return operations;
    }
};