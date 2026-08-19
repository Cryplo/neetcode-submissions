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


// preorder is root, left, right
// inorder is left, root, right

class Solution {
public:

    TreeNode* recurs(vector<int>& preorder, int l, int r,  unordered_map<int, int>& lookup) {
        if(l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[l]);
        for(int i = l + 1; i <= r; i++){
            if(lookup[preorder[i]] > lookup[preorder[l]]){
                root->left = recurs(preorder, l + 1, i - 1, lookup);
                root->right = recurs(preorder, i, r, lookup);
                return root;
            }
        }
        root->left = recurs(preorder, l + 1, r, lookup);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> lookup;
        for(int i = 0; i < inorder.size(); i++){
            lookup[inorder[i]] = i;
        }
        return recurs(preorder, 0, preorder.size() - 1, lookup);
    }
};
