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

    void traverse(TreeNode* curr, vector<int>& res){
        if(curr == nullptr) return;
        traverse(curr->left, res);
        res.push_back(curr->val);
        traverse(curr->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        traverse(root, sol);
        return sol;
    }
};