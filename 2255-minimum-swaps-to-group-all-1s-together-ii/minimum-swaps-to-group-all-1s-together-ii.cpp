class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int num : nums) {
            if (num == 1) ones++;
        }
        if (ones == 0 || ones == n) return 0;
        
        int maxOnesInWindow = 0;
        int currentOnes = 0;
        
        for (int i = 0; i < ones; i++) {
            if (nums[i] == 1) currentOnes++;
        }
        maxOnesInWindow = currentOnes;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) currentOnes--;
            if (nums[(i + ones) % n] == 1) currentOnes++;
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }
        return ones - maxOnesInWindow;
    }
};