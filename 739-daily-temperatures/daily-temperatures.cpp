class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> v;
        int n = temperatures.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()) {
                v.push_back(-1);  
            }
            else if(!st.empty() && st.top().first > temperatures[i]){
                v.push_back(st.top().second);
            }
            else if(!st.empty() && st.top().first <= temperatures[i]){
                while(!st.empty() && st.top().first <= temperatures[i]){
                    st.pop();
                }
                if(st.empty()){
                    v.push_back(-1);
                } else {
                    v.push_back(st.top().second);
                }
            }
            st.push({temperatures[i], i});
        }
        reverse(v.begin(), v.end());
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(v[i] == -1) {
                ans[i] = 0;
            } else {
                ans[i] = v[i] - i;
            }
        }
        return ans;
    }
};