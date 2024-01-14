class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        unordered_map<char, int> freq1, freq2;

        // Count frequency of characters in word1
        for (char ch : word1) {
            freq1[ch]++;
        }

        // Count frequency of characters in word2
        for (char ch : word2) {
            freq2[ch]++;
        }

        // Check if both strings have the same set of characters
        vector<int> count1, count2;
        for (auto& entry : freq1) {
            count1.push_back(entry.second);
        }

        for (auto& entry : freq2) {
            if (freq1.find(entry.first) == freq1.end()) {
                return false;  // Different set of characters
            }
            count2.push_back(entry.second);
        }

        // Sort the frequency counts
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        // Check if the frequency counts are the same
        return count1 == count2;
    }
};