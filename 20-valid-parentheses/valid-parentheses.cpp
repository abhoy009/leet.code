class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp{
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for (auto c : s) {
            if (mp.find(c) == mp.end()) {
                st.push(c);
            } else {
                if (st.empty() || st.top() != mp[c]) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};