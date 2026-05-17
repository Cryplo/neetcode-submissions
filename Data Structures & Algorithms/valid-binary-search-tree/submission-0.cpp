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
    bool recurs(TreeNode* current){
        if(current->left){
            if(current->left->val >= current->val) return false;
            if(!recurs(current->left)) return false;
        } 
        if(current->right){
            if(current->right->val <= current->val) return false;
            if(!recurs(current->right)) return false;
        } 
        return true;
    }
    bool isValidBST(TreeNode* root) {
       return recurs(root); 
    }
};
