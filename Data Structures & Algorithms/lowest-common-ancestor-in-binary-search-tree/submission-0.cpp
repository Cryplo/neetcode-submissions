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
    TreeNode* recurs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(p == node || q == node) return node; 
        if((p->val < node->val && q->val > node->val) || (p->val > node->val && q->val < node->val)) return node;
        if(p->val < node->val) return recurs(node -> left, p, q);
        return recurs(node -> right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // the tree is a BST so this means that we can find where they diverge and return that as the answer
        return recurs(root, p, q);
    }
};
