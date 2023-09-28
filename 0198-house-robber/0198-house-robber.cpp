class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prevMax = nums[0];  
        int currMax = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int temp = currMax;
            currMax = max(currMax, prevMax + nums[i]);
            prevMax = temp;
        }
        
        return currMax; 
    }
};
