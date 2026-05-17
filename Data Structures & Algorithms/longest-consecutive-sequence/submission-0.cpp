class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Solution is basically just have a set/map to keep track of which numbers have existed
        //then, update the number for the left and right of the range
        //also have a global max to keep track of what the max is
        int mn = 1;
        // 
        unordered_map<int, pair<int, int>> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.count(nums[i]) == 0 && (m.count(nums[i] - 1) != 0 || m.count(nums[i] + 1) != 0)){ //this number is consecutive
                // there was one found before
                if(m.count(nums[i] - 1) && ! m.count(nums[i] + 1)){
                    //take the left most of this range and set it's right value to current
                    m[m[nums[i] - 1].first].second = nums[i];
                    m[nums[i]] = {m[nums[i] - 1].first, nums[i]};
                    mn = max(mn, m[nums[i]].second - m[nums[i]].first + 1);
                } 
                else if(m.count(nums[i] + 1) && !m.count(nums[i] - 1)){
                    m[m[nums[i] + 1].second].first = nums[i];
                    m[nums[i]] = {nums[i], m[nums[i] + 1].second};
                    mn = max(mn, m[nums[i]].second - m[nums[i]].first + 1);
                }
                else{
                    m[m[nums[i] - 1].first].second = m[nums[i] + 1].second;
                    m[m[nums[i] + 1].second].first = m[nums[i] - 1].first;
                    m[nums[i]] = {m[nums[i] - 1].first, m[nums[i] + 1].second};
                    mn = max(mn, m[nums[i]].second - m[nums[i]].first + 1);
                }
            }
            else if(m.count(nums[i]) == 0){
              m[nums[i]] = {nums[i], nums[i]};  
            }
            else{
               //ignore this case 
            }
        }
        return mn;
    }
};
