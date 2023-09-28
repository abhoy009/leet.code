class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;

        unordered_set<char> charSet;
        
        int left = 0; 
        int right = 0; 
        int maxLength = 0; 
        
        while (right < n) {
            if (charSet.count(s[right]) == 0) {
                
                charSet.insert(s[right]);
                right++;
                maxLength = max(maxLength, right - left); 
            } else {
                
                charSet.erase(s[left]);
                left++;
            }
        }
        
        return maxLength;
    }
};
