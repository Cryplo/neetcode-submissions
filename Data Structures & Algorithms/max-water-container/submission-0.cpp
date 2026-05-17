class Solution {
public:
    int maxArea(vector<int>& heights) {
      int lp = 0;
      int rp = heights.size() - 1;
      int maxn = 0;
      while(lp != rp){
        maxn = max(maxn, (rp - lp) * min(heights[lp], heights[rp]));
        if(heights[lp] < heights[rp]) lp++;
        else rp--;
      }
      return maxn;
    }
};
