class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // appears once set
        // appears twice set
        // appears three or more times set
        vector<unordered_set<int>> s(3);
        for(int i = 0; i < nums.size(); i++){
            bool seen = false;
            for(int j = 0; j < 2; j++){
                if(s[j].count(nums[i]) != 0){
                    s[j].erase(s[j].find(nums[i]));
                    s[j+1].insert(nums[i]);
                    seen = true;
                    break;
                }
            }
            if(s[2].count(nums[i]) == 0 && !seen){
                s[0].insert(nums[i]);
            }
        }
        set<multiset<int>> sol;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                int a = nums[i];
                int b = nums[j];
                int c = - (nums[i] + nums[j]);
                if(sol.count({a, b, c}) != 0) continue;
                vector<bool> v;
                for(int n = 0; n < 3; n++){
                    v.push_back(s[n].count(c) != 0);
                }
                if(a == b && b == c){
                    if(v[2]) sol.insert({a, b, c});
                }
                else if((a == c || b == c) ){
                    if((v[2] || v[1])) sol.insert({a, b, c});
                }
                else if((v[2] || v[1] || v[0])){
                    sol.insert({a, b, c});
                }
            }
        }
        vector<vector<int>> solv;
        for(multiset<int> se : sol){
            vector<int> v;
            for(int l : se) v.push_back(l);
            solv.push_back(v);
        }
        return solv;
    }
};
