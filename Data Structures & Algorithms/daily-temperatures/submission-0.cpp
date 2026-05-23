class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> sol(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(s.size() > 0){
                if(temperatures[i] > temperatures[s.top()]){
                    sol[s.top()] = i - s.top();
                    s.pop();
                } else break;
            }
            s.push(i);
        }
        return sol;
    }
};
