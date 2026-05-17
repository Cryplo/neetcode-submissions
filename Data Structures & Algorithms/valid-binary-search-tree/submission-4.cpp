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
    bool recurs(TreeNode* current, int lt, int gt, bool ltv, bool gtv){
        if(ltv && current->val > lt) return false;
        if(gtv && current->val < gt) return false;
        if(current->left){
            if(!recurs(current->left, current->val, gt, true, gtv)) return false;
        } 
        if(current->right){
            if(!recurs(current->right, lt, current->val, ltv, true)) return false;
        } 
        return true;
    }
    bool isValidBST(TreeNode* root) {
       return recurs(root, root->val, root->val, false, false); 
    }
};

