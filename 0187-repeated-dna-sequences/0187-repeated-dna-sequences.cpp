class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> sequenceCount; // To store the count of sequences
        int n = s.length();
        
        if (n <= 10) {
            return result; // If the input is less than 10 characters, there can't be repeated sequences.
        }
        
        for (int i = 0; i <= n - 10; ++i) {
            string sequence = s.substr(i, 10); // Get the current 10-character sequence
            
            if (sequenceCount.find(sequence) != sequenceCount.end()) {
                // If the sequence is already in the map, increment its count
                sequenceCount[sequence]++;
            } else {
                // If the sequence is not in the map, add it with a count of 1
                sequenceCount[sequence] = 1;
            }
        }
        
        // Iterate through the map and add sequences with a count greater than 1 to the result
        for (const auto& entry : sequenceCount) {
            if (entry.second > 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
