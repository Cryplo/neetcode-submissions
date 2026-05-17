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
    bool recurs(TreeNode* current, int min_right, int max_left){
        if(current->left){
            if(current->left->val >= min_right) return false;
            if(!recurs(current->left, current->left->val, max_left)) return false;
        } 
        if(current->right){
            if(current->right->val <= max_left) return false;
            if(!recurs(current->right, min_right, current->right->val)) return false;
        } 
        return true;
    }
    bool isValidBST(TreeNode* root) {
       return recurs(root, root->val, root->val); 
    }
};

