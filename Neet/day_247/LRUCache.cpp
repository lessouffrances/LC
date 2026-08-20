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

        // about to exceed the cap
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
    int cap = 0;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
};
    
   