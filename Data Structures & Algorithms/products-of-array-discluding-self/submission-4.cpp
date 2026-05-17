class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool zero = false;
        int normal = 0;
        for(int i = 0; i < nums.size(); i++){
            zero = nums[i] == 0 || zero;
            if(nums[i] != 0){
                prod *= nums[i];
                normal++;
            } 
        } 
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(normal <= 1){
                res.push_back(0);
            }
            else if(zero){
                res.push_back(nums[i] == 0 ? prod : 0); 
            }
            else{
                res.push_back(prod / nums[i]);
            }
        }
        return res;
    }
};
