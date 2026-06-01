class Solution {
public:

    void gen(string digits, int index, vector<string> &sol, vector<vector<char>> &m, string &s){
        if(index == digits.size()){
            if(index != 0)sol.push_back(s);
            return;
        }
        for(char c : m[digits[index] - '2']){
            s += c;
            gen(digits, index + 1, sol, m, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<vector<char>> m = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        };
        vector<string> sol;
        string s;
        gen(digits, 0, sol, m, s);
        return sol;
    }
};
