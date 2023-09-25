class Solution {
public:
    int minPartitions(string n) {
        
        int maxDigit = 0;
        for (char digit : n) {
            int currentDigit = digit - '0'; 
            maxDigit = max(maxDigit, currentDigit);
        }
        
        return maxDigit;
    }
};
