class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);
        for(char c : s1) f1[c - 'a']++;
        for(int i = 0; i < s2.size(); i++){
            f2[s2[i] - 'a']++;
            if(i >= s1.size()) f2[s2[i - s1.size()] - 'a']--; 
            bool works = true;
            for(int j = 0; j < 26; j++){
                if(f1[j] != f2[j]) works = false;
            }
            if(works) return true;
        }
        return false;
    }
};