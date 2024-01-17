class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrences;

        // Count occurrences of each unique number
        for (int num : arr) {
            occurrences[num]++;
        }

        unordered_set<int> uniqueOccurrencesSet;

        // Check if the number of occurrences is unique
        for (const auto& entry : occurrences) {
            if (!uniqueOccurrencesSet.insert(entry.second).second) {
                return false;  // Duplicate number of occurrences found
            }
        }

        return true;
    }
};