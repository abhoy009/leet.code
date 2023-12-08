/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumFrequency;
        int maxFrequency = 0;

        calculateSubtreeSum(root, sumFrequency, maxFrequency);

        vector<int> result;
        for (const auto& entry : sumFrequency) {
            if (entry.second == maxFrequency) {
                result.push_back(entry.first);
            }
        }

        return result;
    }

private:
    int calculateSubtreeSum(TreeNode* node, unordered_map<int, int>& sumFrequency, int& maxFrequency) {
        if (node == nullptr) {
            return 0;
        }

        int leftSum = calculateSubtreeSum(node->left, sumFrequency, maxFrequency);
        int rightSum = calculateSubtreeSum(node->right, sumFrequency, maxFrequency);

        int subtreeSum = leftSum + rightSum + node->val;
        sumFrequency[subtreeSum]++;

        maxFrequency = max(maxFrequency, sumFrequency[subtreeSum]);

        return subtreeSum;
    }
};