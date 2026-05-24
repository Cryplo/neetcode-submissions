class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!m.contains(key)) return "";
        if(m[key][0].first > timestamp) return "";
        int lp = 0;
        int rp = m[key].size() - 1;
        while(lp < rp){
            int mid = (lp + rp + 1) / 2;
            if(m[key][mid].first <= timestamp){
                lp = mid;
            } else {
                rp = mid - 1;
            }
        }
        return m[key][lp].second;
    }
};
