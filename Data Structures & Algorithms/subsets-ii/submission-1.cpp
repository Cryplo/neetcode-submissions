class Solution {
public:

    void gen(vector<int>& nums, vector<int> &v, int idx, vector<vector<int>> &sol){
        if(idx == nums.size()){
            sol.push_back(v);
            return;
        }
        sol.push_back(v); // end it here
        v.push_back(nums[idx]);
        gen(nums, v, idx + 1, sol);
        v.pop_back();
        for(int i = idx + 1; i < nums.size(); i++){
            if(nums[idx] != nums[i] && nums[i] != nums[i - 1]) {
                v.push_back(nums[i]);
                gen(nums, v, i + 1, sol);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        vector<int> v;
        gen(nums, v, 0, sol);
        return sol;
    }
};
