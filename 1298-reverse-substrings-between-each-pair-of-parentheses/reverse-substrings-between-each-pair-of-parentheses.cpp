class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> len;
        string res;

        for(char ch: s){
            if(ch == '('){
                len.push(res.length());
            }else if(ch == ')'){
                int l = len.top();
                len.pop();
                reverse(begin(res)+l,end(res));
            }else{
                res.push_back(ch);
            }
        }
        return res;
    }
};