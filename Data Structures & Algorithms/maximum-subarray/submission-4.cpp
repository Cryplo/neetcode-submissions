class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];//-2
        int minn = min(nums[0], 0); //-2
        int sol = nums[0]; //-2
        for(int i = 1; i < nums.size(); i++){
            minn = min(sum, minn); // -3
            sum += nums[i]; // -3
            sol = max(sum - minn, sol); //
        }
        return sol;
    }
};
