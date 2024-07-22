class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        vector<string> ans;
        for (int i = 0; i < names.size(); i++)
            v.push_back({heights[i], names[i]});
        
        sort(v.rbegin(),v.rend());
        for(auto a: v){
            ans.push_back(a.second);
        }
        return ans;
    }
};