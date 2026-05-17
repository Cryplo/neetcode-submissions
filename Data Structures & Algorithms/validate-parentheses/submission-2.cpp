class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        set<char> starts = {'(', '{', '['};
        unordered_map<char, char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
       for(int i = 0; i < s.length(); i++){
        if(starts.count(s[i]) != 0){
            st.push(s[i]);
        } else{
            if(st.size() == 0) return false;
            if(s[i] != m[st.top()]) return false;
            st.pop();
        }
       }
       if(st.size() > 0) return false;
       return true;
    }
};
