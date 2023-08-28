class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Sorting the candidates for easier processing
        backtrack(result, current, candidates, target, 0);
        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates to avoid duplicate combinations
            }
            
            if (candidates[i] > target) {
                break; // Since candidates are sorted, no need to check further
            }
            
            current.push_back(candidates[i]);
            backtrack(result, current, candidates, target - candidates[i], i + 1); // Move to the next candidate
            current.pop_back(); // Backtrack to try other combinations
        }
    }
};
