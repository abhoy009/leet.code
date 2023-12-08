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
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        ostringstream result;
        preorderTraversal(root, result);

        return result.str();
    }

private:
    void preorderTraversal(TreeNode* node, ostringstream& result) {
        if (node != nullptr) {
            result << node->val;

            if (node->left != nullptr || node->right != nullptr) {
                result << "(";
                preorderTraversal(node->left, result);
                result << ")";
            }

            if (node->right != nullptr) {
                result << "(";
                preorderTraversal(node->right, result);
                result << ")";
            }
        }
    }
};