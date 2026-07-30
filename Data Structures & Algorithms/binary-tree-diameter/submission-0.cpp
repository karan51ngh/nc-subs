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
        if(root == nullptr) return 0;

        int oneHeight  = (root->left != nullptr || root->right != nullptr) ? 1 : 0;
        return oneHeight + max(height(root->left), height(root->right));
    }

    void actualDiameterOfBinaryTree(TreeNode* root, int &maxD) {
        if(root == nullptr) return;

        actualDiameterOfBinaryTree(root->left, maxD);
        actualDiameterOfBinaryTree(root->right, maxD);

        int leftHeight = (root->left == nullptr) ? 0 : 1;
        int rightHeight = (root->right == nullptr) ? 0 : 1; 
        
        maxD = max(
            height(root->left) + height(root->right) + leftHeight + rightHeight 
            , maxD);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        

        int maxD = 0;

        actualDiameterOfBinaryTree(root, maxD);
        return maxD;
        
    }
};
