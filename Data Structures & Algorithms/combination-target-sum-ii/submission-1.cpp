class Solution {
public:

    void gen(vector<int>& candidates,
        int target,
        int sum,
        int idx,
        vector<int>& sumOfRemaining,
        vector<int>& path,
        vector<vector<int>>& sol){
        if(idx == candidates.size()){
            if(sum == target) sol.push_back(path);
            return;
        }
        if(sum > target) return;
        if(sumOfRemaining[idx] + sum + candidates[idx] < target) return;

        int i = 1;
        while(idx + i < candidates.size() && candidates[idx + i] == candidates[idx]){
            i++;
        }
        gen(candidates, target, sum, idx + i, sumOfRemaining, path, sol);
        path.push_back(candidates[idx]);
        sum += candidates[idx];
        gen(candidates, target, sum, idx + 1, sumOfRemaining, path, sol);
        path.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sumOfRemaining(candidates.size(), 0);
        for(int i = candidates.size() - 2; i >= 0; i--){
            sumOfRemaining[i] = sumOfRemaining[i + 1] + candidates[i + 1];
        }
        vector<vector<int>> sol;
        vector<int> path;
        gen(candidates, target, 0, 0, sumOfRemaining, path, sol);
        return sol;
    }
};
