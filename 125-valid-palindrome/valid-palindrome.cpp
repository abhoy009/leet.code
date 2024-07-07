class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(
            remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }),
            s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if (s.empty()) {
            return true;
        }

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};