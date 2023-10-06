class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        string current; 
        generateCombinations(result, mapping, digits, current, 0);
        return result;
    }
    
private:
    void generateCombinations(vector<string>& result, const vector<string>& mapping, const string& digits, string& current, int index) {
        if (index == digits.length()) {
            result.push_back(current); 
            return;
        }
        
        int digit = digits[index] - '0'; 
        string letters = mapping[digit];
        
        for (char letter : letters) {
            current.push_back(letter); 
            generateCombinations(result, mapping, digits, current, index + 1); 
            current.pop_back();
        }
    }
};
