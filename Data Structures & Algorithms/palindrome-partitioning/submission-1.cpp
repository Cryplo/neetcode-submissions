class Solution {
public:
    /*
        Solution idea:
        start with string fully splitted, this is a palindrome
        you can either combine two strings or skip
        This would be too time complex, so we need to implement backtracking to save time
        special cases for when length of string = 1, but otherwise if we
        assume that string as a well-formed palindrome then left and right must be equal palindromes
    */

    void gen(int i, vector<string> vv, vector<vector<string>> & sol){
        if(i >= vv.size()) return;
        vector<string> v = vv;
        if(v[i].length() == 1){
            if(i < v.size() - 1 && v[i + 1] == v[i]){
                v[i] += v[i + 1];
                v.erase(v.begin() + i + 1);
                sol.push_back(v);
                gen(i, v, sol);
            }
        }
        v = vv;
        if(i > 0 && i < v.size() - 1){
            if(v[i - 1] == v[i + 1]){
                v[i - 1] += v[i] + v[i + 1];
                v.erase(v.begin() + i, v.begin() + i + 2); // exclusive end
                sol.push_back(v);
                gen(i - 1, v, sol);
            }
        }
        v = vv;
        gen(i + 1, v, sol);
    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> sol;
        for(int i = 0; i < s.length(); i++){
            v.push_back(string(1, s[i]));
        }
        sol.push_back(v);
        gen(0, v, sol);
        return sol;
    }
};
