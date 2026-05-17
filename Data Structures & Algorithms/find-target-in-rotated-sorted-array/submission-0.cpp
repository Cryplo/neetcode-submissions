class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l != r && l + 1 != r){
            cout << nums[l] << " " << nums[r] << endl;
            int c = (r - l) / 2 + l; //favors left when even, include
            if(nums[l] >= nums[c] && (target >= nums[l] || target <= nums[c])){
                r = c;
                continue;
            }
            //on right side and right side has gap
            if(nums[r] <= nums[c] && (target <= nums[r] || target >= nums[c])){
                    l = c;
                    continue;
            }
            //need to write cases for normal range
            if(target == nums[c]){
                l = c; r = c;
            }
            else if(target < nums[c]) r = c;
            else l = c;
        }
        if(nums[l] == target) return l;
        if(nums[r] == target) return r;
        return -1;
    }
};
