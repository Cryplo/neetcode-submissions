class Solution {
public:

    void gen(vector<int> &nums, vector<bool> &b, vector<int>& v, vector<vector<int>>& sol){
        if(v.size() == nums.size()) {
            sol.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!b[i]){
                v.push_back(nums[i]);
                b[i] = true;
                gen(nums, b, v, sol);
                b[i] = false;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> b(nums.size(), false);
        vector<int> v;
        vector<vector<int>> sol;
        gen(nums, b, v, sol);
        return sol;
    }
};
