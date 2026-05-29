class Solution {
public:
    void gen(vector<int>& nums, vector<int> v, int idx, vector<vector<int>> &sol){
        if(idx == nums.size()){
            sol.push_back(v);
            return;
        }
        gen(nums, v, idx + 1, sol);
        v.push_back(nums[idx]);
        gen(nums, v, idx + 1, sol);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        gen(nums, {}, 0, sol);
        return sol;
    }
};
