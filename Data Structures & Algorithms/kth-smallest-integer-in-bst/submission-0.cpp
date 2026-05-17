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
    // just DFS to the left and then go to the right and see
    // recurs returns the count
    int recurs(TreeNode* current, int count, int k, int& sol){
        cout << current->val << " " << count << endl;
        // we have reached a dead end and increase count by 1 and backtrack
        if(current->left == nullptr && current->right == nullptr){
            if(count + 1 == k){
                sol = current->val;
                return count + 1;
            }
            return count + 1; 
        }
        if(current->left){
            // this is the new count
            count = recurs(current->left, count, k, sol);
        } 
        if(count + 1 == k){
            sol = current->val;
            return count + 1;
        }
        count += 1;
        if(current->right){
            // this is the new count
            count = recurs(current->right, count, k, sol);
        } 
        return count;
    }
    int kthSmallest(TreeNode* root, int k) {
        int sol;
        recurs(root, 0, k, sol); 
        return sol;
    }
};

