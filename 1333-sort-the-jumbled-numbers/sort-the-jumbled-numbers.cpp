class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            string mapped = "";
            for(char c : s) {
                mapped += to_string(mapping[c - '0']);
            }
            int val = mapped.empty() ? 0 : stoi(mapped);
            v.push_back({val, i});
        }
        
        sort(v.begin(), v.end());
        
        vector<int> result;
        for(auto p : v) {
            result.push_back(nums[p.second]);
        }
        
        return result;
    }
};