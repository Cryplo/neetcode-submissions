class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || 
               tokens[i] == "-" ||
               tokens[i] == "*" ||
               tokens[i] == "/"){
                int y = stack.top();
                stack.pop();
                int x = stack.top();
                stack.pop();
                if(tokens[i] == "+") stack.push(x + y);
                if(tokens[i] == "-") stack.push(x - y);
                if(tokens[i] == "*") stack.push(x * y);
                if(tokens[i] == "/") stack.push(x / y);
            }
            else{
                stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};
