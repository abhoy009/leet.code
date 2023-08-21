class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return ""; // If the input vector is empty, there's no common prefix.
        }
        
        string prefix = strs[0]; // Start with the first string as the initial common prefix.
        
        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1); // Reduce the prefix length.
                if (prefix.empty()) {
                    return ""; // If the prefix becomes empty, there's no common prefix.
                }
            }
        }
        
        return prefix;
    }
};