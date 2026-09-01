class Solution {
public:
    int rob(vector<int>& nums) {
        int sol = nums[0];
        vector<int> dp(nums.size(), 0);
        for(int i = 1; i < nums.size(); i++){
            if(i + 1 < nums.size()) dp[i + 1] = max(dp[i + 1], dp[i]);
            dp[i] += nums[i];
            if(i + 2 < nums.size()) dp[i + 2] = max(dp[i + 2], dp[i]);
            sol = max(sol, dp[i]);
        }
        for(int i = 0; i < nums.size(); i++) dp[i] = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(i + 1 < nums.size()) dp[i + 1] = max(dp[i + 1], dp[i]);
            dp[i] += nums[i];
            if(i + 2 < nums.size()) dp[i + 2] = max(dp[i + 2], dp[i]);
            sol = max(sol, dp[i]);
        }
        return sol;
    }
};
