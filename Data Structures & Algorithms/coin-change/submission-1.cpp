class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount + 1, -1);
        v[0] = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == -1) continue;
            for(int c : coins){
                if(c > amount) continue;
                if(c + i <= amount){
                    v[c + i] = v[c + i] == -1 ? v[i] + 1 :
                    min(v[c + i], v[i] + 1);
                }
            }
        }
        return v[amount];
    }
};
