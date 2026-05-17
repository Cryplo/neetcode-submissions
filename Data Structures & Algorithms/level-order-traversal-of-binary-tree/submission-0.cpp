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
    void recurs(int index, vector<vector<int>> &sol, TreeNode* current){
        if(current == nullptr) return;
        if(sol.size() == index) {
            sol.push_back({});
        }
        sol[index].push_back(current->val);
        if(current->left) recurs(index + 1, sol, current->left);
        if(current->right) recurs(index + 1, sol, current->right);
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        recurs(0, sol, root);
        return sol;
    }
};
