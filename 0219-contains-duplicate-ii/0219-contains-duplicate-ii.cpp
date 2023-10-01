class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numIndex; 
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            
            if (numIndex.find(num) != numIndex.end() && i - numIndex[num] <= k) {
                
                return true;
            }
            
            numIndex[num] = i;
        }
        
        
        return false;
    }
};
