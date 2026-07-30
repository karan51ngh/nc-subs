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

    bool isActualValidBST(TreeNode* root, int prevMin, int prevMax) {
        if(root == nullptr) return true;

        bool leftCheck = root -> left 
            ? (root->left->val < root->val)
            : true;

        bool rightCheck = root -> right 
            ? (root->right->val > root->val)
            : true;

        return 
            leftCheck 
            && rightCheck
            && (root->val > prevMin) && (root->val < prevMax)
            && isActualValidBST(root->right, max(prevMin, root->val), prevMax)
            && isActualValidBST(root->left, prevMin, min(prevMax, root->val));
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return isActualValidBST(root, -1000, 1000);
    }
};
