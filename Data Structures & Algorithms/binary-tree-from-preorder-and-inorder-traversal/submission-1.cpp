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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.size() == 0) return nullptr;

        vector<int> inorderLeft;
        vector<int> inorderRight;
        vector<int> preorderLeft;
        vector<int> preorderRight;

        TreeNode* root = new TreeNode(preorder[0]);

        int i = 0;
        while(inorder[i] != preorder[0]) {
            inorderLeft.push_back(inorder[i]);
            i++;
        }
        i++;
        while(i < preorder.size()) {
            inorderRight.push_back(inorder[i]);
            i++;
        }

        int j = 1;

        while(preorderLeft.size() < inorderLeft.size()) {
            preorderLeft.push_back(preorder[j]);
            j++;
        }

        while(j < preorder.size()) {
            preorderRight.push_back(preorder[j]);
            j++;
        }

        root->left = buildTree(preorderLeft,inorderLeft);
        root->right = buildTree(preorderRight,inorderRight);
        
        return root;
    }
};
