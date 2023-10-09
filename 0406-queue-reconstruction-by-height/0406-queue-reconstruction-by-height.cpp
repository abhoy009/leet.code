class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        
        vector<vector<int>> result;
        
        for (const vector<int>& p : people) {
            result.insert(result.begin() + p[1], p);
        }
        
        return result;
    }
};
