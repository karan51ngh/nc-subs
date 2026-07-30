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
    int actualGoodNodes(TreeNode* root, int prev) {
        
        if(root == nullptr ) return 0;

        int nodeCheck = root->val >= prev ? 1 : 0;

        return nodeCheck 
            + actualGoodNodes(root->left, max(prev,root->val))
            + actualGoodNodes(root->right, max(prev,root->val));
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr ) return 0;

        return actualGoodNodes(root, root->val);
    }
};
