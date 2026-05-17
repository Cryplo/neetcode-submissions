class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lag = 0;
        map<char, int> m;
        int maxl = s.length() == 0 ? 0 : 1;
        for(int i = 0; i < s.length(); i++){
            if(m.count(s[i]) == 0){
                m[s[i]] = i;
                maxl = max(maxl, i + 1 - lag);
            }    
            else{
                lag = m[s[i]] + 1;
                m[s[i]] = i;
                maxl = max(maxl, i - lag);
            }
        }
        return maxl;
    }
};
