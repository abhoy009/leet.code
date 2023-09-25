class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int votes = 1;
        
        for(int i=1;i<nums.size();i++){
            if(votes == 0){
                votes++;
                major = nums[i];
            }
            else if(major == nums[i]){
                votes++;
            }
            else{
                votes--;
            }
        }
        return major;
    }
};