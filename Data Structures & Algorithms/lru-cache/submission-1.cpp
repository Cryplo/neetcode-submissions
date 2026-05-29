class LRUCache {
private:
    list<int> lru;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> tracker;
    int capacity_;

public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if(tracker.contains(key)){
            lru.erase(tracker[key]); // erase key from LRU
            lru.push_back(key);
            tracker[key] = --lru.end();
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lru.size() == capacity_){
            if(tracker.contains(key)){
                lru.erase(tracker[key]); // erase key from LRU
            }
            else{
                tracker.erase(lru.front());
                lru.erase(lru.begin());
            }
        }
        else{
            if(tracker.contains(key)){
                lru.erase(tracker[key]); // erase key from LRU
            }
        }
        lru.push_back(key);
        cache[key] = value;
        tracker[key] = --lru.end();
    }
};
