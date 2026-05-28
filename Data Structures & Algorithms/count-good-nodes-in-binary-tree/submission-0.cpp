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

    void traverse(TreeNode* curr, int maxn, int& sol){
        if(curr == nullptr) return;
        if(curr->val >= maxn){
            ++sol;
            maxn = curr->val;
        }
        traverse(curr->left, maxn, sol);
        traverse(curr->right, maxn, sol);
    }

    int goodNodes(TreeNode* root) {
        int sol = 0;
        int maxn = root->val;
        traverse(root, maxn, sol); 
        return sol;
    }
};
