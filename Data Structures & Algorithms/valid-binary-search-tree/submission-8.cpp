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
    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (node == NULL) return true;

        if (minNode != NULL && node->val <= minNode->val) {
            return false;
        }
        
        if (maxNode != NULL && node->val >= maxNode->val) {
            return false;
        }

        return validate(node->left, minNode, node) && 
               validate(node->right, node, maxNode);

    }
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }
};
