class Solution {
public:
    bool isAnagram(string s, string t) {
      map<int, int> m;
      for(int i = 0; i < s.length(); i++){
        if(m.count(s[i]) == 0) m[s[i]] = 1;
        else ++m[s[i]];
      }
      for(int i = 0; i < t.length(); i++){
        if(m.count(t[i]) == 0) return false;
        else --m[t[i]];
        if(m[t[i]] == 0){
            m.erase(t[i]);
        }
      }
      return true;
    }
};
