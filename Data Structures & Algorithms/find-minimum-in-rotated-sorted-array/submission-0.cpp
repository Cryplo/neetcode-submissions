class Solution {
public:
    int findMin(vector<int> &nums) {
    //basically the solution is
    //to look for where it decreases.
    //to do so, go to the center and check with the left most and right most
    //this will help determine which side has the minimum
    int l = 0;
    int r = nums.size() - 1;    
    while(l != r){
        int c = (r - l)/2 + l;
        //in the left half
        if(nums[l] > nums[c]){
            r = c;
            continue;
        }
        //in the right half
        if(nums[r] < nums[c]){
            l = c + 1;
            continue;
        }
        //only 2 elements left
        if(nums[r] < nums[l]) return nums[r];
        else return nums[l];
    }
    return nums[l];
    }
};
