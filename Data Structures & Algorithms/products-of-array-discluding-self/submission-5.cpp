class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pe;
        vector<int> po;
        int prod = 1;
        for(int i = 0; i < nums.size(); i++){
            prod *= nums[i];
            pe.push_back(prod);
        }
        prod = 1;
        for(int i = 0; i < nums.size(); i++){
            prod *= nums[nums.size() - i - 1];
            po.push_back(prod);
        }
        
        vector<int> sol;
        for(int i = 0; i < nums.size(); i++){
            int prod = 1;
            if(i > 0){
                prod *= pe[i - 1];
            }
            if(i < nums.size() -1 ){
                prod *= po[nums.size() - i - 2];
            }
            sol.push_back(prod);
        }
        return sol;
    }
};
