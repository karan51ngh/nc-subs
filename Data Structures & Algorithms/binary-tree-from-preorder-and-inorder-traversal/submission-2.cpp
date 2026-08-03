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

        if (preorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);

        if (preorder.size() == 1) {
            root -> left = nullptr;
            root -> right = nullptr;
            return root;
        }

        vector<int> leftInorder;
        vector<int> rightInorder;

        vector<int> leftPreorder;
        vector<int> rightPreorder;
        
        bool foundRoot = false;
        for (auto &n: inorder) {
            if (n == preorder[0]) {
                foundRoot = true;
                continue;
            }
            (foundRoot == false) ? leftInorder.push_back(n) : rightInorder.push_back(n);
        }
        
        int i = 1;
        while (leftPreorder.size() < leftInorder.size()) {
            leftPreorder.push_back( preorder[i] );
            i++;
        }

        while (rightPreorder.size() < rightInorder.size()) {
            rightPreorder.push_back( preorder[i] );
            i++;
        }
        
        
        root -> left = buildTree(leftPreorder, leftInorder);
        root -> right = buildTree(rightPreorder, rightInorder);


        return root;
    }
};
