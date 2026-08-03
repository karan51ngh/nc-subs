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
    void inOrderTraverse(TreeNode* root , vector <int> &iot ) {

        if (root == nullptr) {
            return;
        }

        inOrderTraverse(root -> left, iot);
        iot.push_back(root->val);
        inOrderTraverse(root -> right, iot);
    }

    int kthSmallest(TreeNode* root, int k) {

        vector <int> iot;

        inOrderTraverse( root , iot );

        return iot[ k - 1 ];
        
    }
};
