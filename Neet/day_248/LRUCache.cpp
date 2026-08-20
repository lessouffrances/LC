class LRUCache 
{
    public:
    LRUCache(int capacity) 
    {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if (!cache.count(key)) return -1;
        auto iter = cache[key];
        // let the iter be the first one
        lru.splice(lru.begin(), lru, iter);
        return lru.begin()->second;
    }
    
    void put(int key, int value) 
    {
        if (cache.count(key)) {
            auto iter = cache[key];
            lru.splice(lru.begin(), lru, iter);
            lru.begin()->second = value;
            return;
        }

        if (lru.size() == cap) {
            int keyToRemove = lru.back().first;
            cache.erase(keyToRemove);
            lru.pop_back();
        }
        lru.push_front( {key, value} );
        cache[key] = lru.begin();
        return;
    }

    private:
    int cap;
    list<pair<int, int>> lru; // a LL containing pair of key and value
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
    // map key to the iterator of the pair 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */