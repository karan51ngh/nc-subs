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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL || root -> val == p -> val || root -> val == q -> val) {
            return root;
        }
        
        TreeNode* leftLowest = lowestCommonAncestor( root -> left, p, q);
        TreeNode* rightLowest = lowestCommonAncestor( root -> right, p, q);
        
        if (leftLowest != NULL && rightLowest != NULL) {
            return root;
        }
        
        if (leftLowest != NULL) {
            return leftLowest;
        } else {
            return rightLowest;
        }
    }
};
