class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int totalSlices = 0;
        vector<unordered_map<long long, int>> dp(n);  // Using long long to prevent overflow
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                // If the difference is within the range of integer values
                if (diff <= INT_MAX && diff >= INT_MIN) {
                    dp[i][diff] += 1;  // Increment the count of valid subsequences ending at index i with difference 'diff'
                    if (dp[j].find(diff) != dp[j].end()) {
                        dp[i][diff] += dp[j][diff];  // Extend the subsequences
                        totalSlices += dp[j][diff];  // Add the count to the total
                    }
                }
            }
        }
        
        return totalSlices;
    }
};
