class Solution {
public:

    void gen(int x, int y, string &s, vector<string> &sol, int n){
        if(s.size() == 2 * n){
            sol.push_back(s);
            return;
        }
        if(y < n){
            s += '(';
            gen(x + 1, y + 1, s, sol, n);
            s.pop_back();
        }
        if(x > 0) {
            s += ')';
            gen(x - 1, y, s, sol, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string s;
        gen(0, 0, s, sol, n);
        return sol;
    }
};
