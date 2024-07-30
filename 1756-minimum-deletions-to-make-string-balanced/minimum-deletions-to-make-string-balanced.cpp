class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int cnt = 0;
        for(int i=s.size();i>=0;i--){
            if(!st.empty() && s[i]=='b' && st.top()=='a'){
                st.pop();
                cnt++;
            }else{
                st.push(s[i]);
            }
        }
        return cnt;
    }
};