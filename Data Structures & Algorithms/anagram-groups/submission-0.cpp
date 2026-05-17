class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<vector<int>, vector<string>> m;
       for(int i = 0; i < strs.size(); i++){
        vector<int> v(26, 0);
        for(int j = 0; j < strs[i].length(); j++){
            v[(int) (strs[i][j] - 'a')]++;
        }
        m[v].push_back(strs[i]);
       } 
       vector<vector<string>> sol;
       for(map<vector<int>, vector<string>>::iterator it = m.begin();
          it != m.end(); it++){
            sol.push_back(it->second);
          }
        return sol;
    }

};
