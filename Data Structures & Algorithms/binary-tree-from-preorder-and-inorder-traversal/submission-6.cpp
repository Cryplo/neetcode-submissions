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

    //lp rp track preorder
    // li ri track inorder
    TreeNode* recurs(vector<int> & preorder, int lp, int rp, int li, int ri, unordered_map<int, int> &lookup, vector<int> & inorder){
        int ci = lookup[preorder[lp]]; //center of inorder
        int leftSize = ci - li;
        int rightSize = ri - ci;
        TreeNode* root = new TreeNode(inorder[ci]);
        if(leftSize > 0)
        root->left = recurs(preorder, lp + 1, lp + leftSize, li, ci - 1, lookup, inorder);
        if(rightSize > 0)
        root->right = recurs(preorder, lp + leftSize + 1, rp, ci + 1, ri, lookup, inorder);
        return root;

        /*
        if(l > r) return nullptr;
        int inorderRootIdx = lookup[preorder[idx]];
        TreeNode* root = new TreeNode(inorder[inorderRootIdx]);
        if(l == r) return root;
        root->left = recurs(preorder, idx + 1, l, inorderRootIdx - 1, lookup, inorder);
        root->right = recurs(preorder, idx + 1 + (inorderRootIdx - l), inorderRootIdx + 1,r, lookup, inorder);
        return root;
        */
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> lookup;
        for(int i = 0; i < preorder.size(); i++){
            lookup[inorder[i]] = i;
        }
        return recurs(preorder, 0, preorder.size() - 1, 0, preorder.size() - 1, lookup, inorder);
    }
};
