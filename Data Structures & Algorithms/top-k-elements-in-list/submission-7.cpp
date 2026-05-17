class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occ;
        vector<set<int>> freq(nums.size() + 1);
        for(int i : nums){
            occ[i]++;
        }
        for(auto p : occ){
            freq[p.second].insert(p.first);
        }
        vector<int> result;
        bool out = false;
        for(int i = freq.size() - 1; i >= 0; i--){
            for(int n : freq[i]){
                result.push_back(n);
                if(result.size() >= k){
                    out = true;
                    break;
                }
            } 
            if(out) break;
        }
        return result;
    }
};




