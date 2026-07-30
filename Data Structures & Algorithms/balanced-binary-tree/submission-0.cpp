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
    int height(TreeNode* root) {
        if(!root) return 0;

        else return 1 + max(height(root->left), height(root->right));

    }
    bool isBalanced(TreeNode* root) {

        if(!root) return true;
        int heightDiff = height(root->left) - height(root->right);
        bool heightCheck = (heightDiff >= -1) && (heightDiff <= 1);
        return heightCheck && isBalanced(root->left) && isBalanced(root->right); 
        
    }
};
