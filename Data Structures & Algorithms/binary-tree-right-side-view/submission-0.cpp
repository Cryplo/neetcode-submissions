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
    void traverse(TreeNode* curr, int depth, vector<int>& sol){
        if(curr == nullptr) return;
        if(depth >= sol.size()) sol.push_back(curr->val);
        else sol[depth] = curr->val;
        traverse(curr->left, depth + 1, sol);
        traverse(curr->right, depth + 1, sol);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        traverse(root, 0, sol);
        return sol;
    }
};
