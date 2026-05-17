class Solution {
public:
    //idea: convert each character to a number, 
    // and then separate characters with commas and separate words with semicolons1
    string encode(vector<string>& strs) {
        string result = "";
        for(string s : strs){
            for(char c : s){
               result += to_string(c - '0');
                result+=",";
            }
            result += ";";
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string curr_word = "";
        string curr_char = "";
        for(char c : s){
            if (c == ','){
                int val = stoi(curr_char);
                char c = val + '0';
                curr_char = "";
                curr_word += c;
            }
            else if (c == ';'){
                result.push_back(curr_word);
                curr_word = "";
            }
            else{
                curr_char += c;
            }
        }
        return result;
    }
};
