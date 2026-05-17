class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        int mn = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[i] += nums[i];
            mn = max(mn, dp[i]);
            if(i + 2 < nums.size()) dp[i + 2] = max(dp[i + 2], dp[i]);
            if(i + 3 < nums.size()) dp[i + 3] = max(dp[i + 3], dp[i]);
        }
        return mn;
    }
};

