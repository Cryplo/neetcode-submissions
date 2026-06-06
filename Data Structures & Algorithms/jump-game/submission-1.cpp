class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int highest = nums.size() - 2;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == 0 && highest == -1){
                highest = i;
            }
            else{
                if(highest != -1){
                    if(nums[i] + i > highest){
                        highest = -1;
                    }
                }
            }
        }
        return highest == -1;
    }
};
