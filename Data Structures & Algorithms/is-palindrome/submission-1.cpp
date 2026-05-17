class Solution {
public:
    bool isPalindrome(string s) {
       int i = 0;
       int j = s.length() - 1;
       while(i != j){
        if(i == j) break;
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))){
           i++; continue; 
        }
        if(!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')))
        {
           j--; continue; 
        }
        if((s[j] >= 'A' && s[j] <= 'Z')) s[j] = s[j] - 'A' + 'a';
        if((s[i] >= 'A' && s[i] <= 'Z')) s[i] = s[i] - 'A' + 'a';
        if(s[i] != s[j]) return false;
        i++;
        if(i == j) break;
        j--;
       }
       return true;
    }
};
