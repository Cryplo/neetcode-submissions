class Solution {
public:
    bool validate(vector<int>& piles, int h, int k){
        int sum = 0;
        for(int i = 0; i < piles.size(); i++){
            sum += piles[i] / k;
            if(piles[i] % k > 0) sum++;
        }
        return sum <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mn = 0;
        for(int i : piles) mn = max(i, mn);
        int lp = 1;
        int rp = mn;
        while(lp < rp){
           int mid = (lp + rp) / 2;
           if(validate(piles, h, mid)){
            rp = mid;
           } else {
            lp = mid + 1;
           }
        }
        return lp;
    }
};
