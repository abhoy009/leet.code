class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> sequenceCount; 
        int n = s.length();
        
        if (n <= 10) {
            return result; 
        }
        
        for (int i = 0; i <= n - 10; ++i) {
            string sequence = s.substr(i, 10); 
            
            if (sequenceCount.find(sequence) != sequenceCount.end()) {
                sequenceCount[sequence]++;
            } else {
                sequenceCount[sequence] = 1;
            }
        }
        
        
        for (const auto& entry : sequenceCount) {
            if (entry.second > 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
