class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lp = 0;
        int rp = nums.size();
        while(lp <= rp){
            int mid = (lp + rp) / 2;
            if(nums[mid] < target) lp = mid + 1;
            else if(nums[mid] > target) rp = mid - 1;
            else return mid;
        }
        return -1;
    }
};
