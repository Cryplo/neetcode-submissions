class Solution {
public:
    bool isAnagram(string s, string t) {
       set<int> a;
       for(int i = 0; i < s.length(); i++){
        a.insert(s[i]);
       }
       for(int j = 0; j < t.length(); j++){
        if(a.count(t[j]) == 0) return false;
       }
       return true;
    }
};
