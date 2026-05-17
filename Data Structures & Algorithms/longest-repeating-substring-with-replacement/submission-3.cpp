class Solution {
public:
    int characterReplacement(string s, int k) {
        //loop through each letter A-Z
        //keep track of how many times the letter occurs, then once it stops, keep track of how many k is needed
        //eventually, for AAABABB we'll have 3A 1? 1A 2?
        //maintain a queue and keep on extending to the right. Anytime K is exceeded then pop from the queue until K is not exceeded.
        //only need to store the information about the last element
        //update sol on every letter
        int sol = 0;
        map<char, pair<queue<int>, int>> m;
        
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            queue<int> q = m[c].first;
            int accCost = m[c].second;
            if(q.size() == 0){
                q.push(i);
            }
            else{
                int lastIndex = q.back();
                q.push(i);
                int cost = i - lastIndex - 1;
                if(accCost + cost > k){
                    while(accCost + cost > k){
                       int prevFront = q.front(); 
                       q.pop();
                       accCost -= q.front() - prevFront - 1;
                    }
                }
                accCost += cost;
            }
            m[c].first = q;
            m[c].second = accCost;
            cout << c << " " << q.back() << q.front() << k << accCost << endl;
            sol = max(sol, q.back() - q.front() + 1 + k - accCost);
            sol = min(sol, (int)s.length());
        }
        return sol;
    }
};
