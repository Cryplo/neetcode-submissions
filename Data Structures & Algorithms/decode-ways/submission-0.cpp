class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '0') dp[i + 1] += dp[i];
            if(i < s.length() - 1 && stoi(s.substr(i, 2)) >= 10 && stoi(s.substr(i, 2)) <= 26){
                dp[i + 2] += dp[i];
            }
        }
        return dp[s.length()];
    }
};