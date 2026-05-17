class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            //check if the complement is alreay in m
            if(m.count(target - nums[i]) == 0){
                m[nums[i]] = i;
            }else{
                return {m[target - nums[i]], i};
            }
        }
        return {-1, -1};
    }
};
