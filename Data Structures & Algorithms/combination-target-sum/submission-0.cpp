class Solution {
public:
    void recurs(vector<int> nums, int index, int total, vector<int> branch, vector<vector<int>> &sol, int target){
        //either skip the current number, add it if possible, or 
        if(index == nums.size()) return;
        if(total == target){
            sol.push_back(branch);
            return;
        }
        recurs(nums, index + 1, total, branch, sol, target);
        branch.push_back(nums[index]);
        total += nums[index];
        if(total <= target) recurs(nums, index, total, branch, sol, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol; 
        recurs(nums, 0, 0, {}, sol, target);
        return sol;
    }
};
