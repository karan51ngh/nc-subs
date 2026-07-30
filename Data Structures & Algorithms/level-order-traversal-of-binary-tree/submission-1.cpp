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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        
        vector<vector<int>> solution;
        if(root == nullptr)
            return solution;
        q.push(root);

        while(q.size() > 0) {
            int size = q.size();

            vector<int> sol;
            for (int i = 0; i < size; i++){
                
                TreeNode* x = q.front();
                sol.push_back(x->val);
                
                if(x->left !=nullptr) q.push(x -> left);
                if(x->right !=nullptr) q.push(x -> right);

                q.pop();
            }
            solution.push_back(sol);
        }


        return solution;
    }
};
