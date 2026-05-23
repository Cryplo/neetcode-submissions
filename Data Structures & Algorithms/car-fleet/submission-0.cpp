class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n, {0, 0});
        for(int i = 0; i < n; i++) cars[i] = {position[i], speed[i]};
        sort(cars.begin(), cars.end());
        stack<double> s;
        for(int i = n - 1; i >= 0; i--){
            if(s.size() > 0){
                if(static_cast<int>(target - cars[i].first) / cars[i].second > s.top()){
                    s.push(static_cast<int>(target - cars[i].first) / cars[i].second);
                }
            } else s.push(static_cast<int>(target - cars[i].first) / cars[i].second);
        }
        return s.size();
    }
};
