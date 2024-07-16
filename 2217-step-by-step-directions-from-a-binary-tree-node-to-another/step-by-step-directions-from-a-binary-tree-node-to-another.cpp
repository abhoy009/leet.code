/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool findPath(TreeNode* node, int value, string& path) {
        if (!node)
            return false;
        if (node->val == value)
            return true;

        if (findPath(node->left, value, path)) {
            path.push_back('L');
            return true;
        }
        if (findPath(node->right, value, path)) {
            path.push_back('R');
            return true;
        }

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        while (!pathToStart.empty() && !pathToDest.empty() &&
               pathToStart.back() == pathToDest.back()) {
            pathToStart.pop_back();
            pathToDest.pop_back();
        }

        return string(pathToStart.length(), 'U') +
               string(pathToDest.rbegin(), pathToDest.rend());
    }
};