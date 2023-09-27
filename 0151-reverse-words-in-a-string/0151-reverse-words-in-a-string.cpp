
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        string reversedString;
        for (const string& w : words) {
            reversedString += w + " ";
        }
        
        if (!reversedString.empty()) {
            reversedString.pop_back();
        }
        
        return reversedString;
    }
};
