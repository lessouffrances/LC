class LRUCache 
{
    public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) 
    {
        if (!cache.count(key)) return -1;
        lru.splice(lru.begin(), lru, cache[key]);
        return cache[key]->second;
    }
    void put(int key, int value) 
    {
        if (cache.count(key)) {
            lru.splice(lru.begin(), lru, cache[key]);
            cache[key]->second = value;
            return;
        }

        if (lru.size() == cap) {
            int toRemoveKey = lru.back().first;
            cache.erase(toRemoveKey);
            lru.pop_back();
        }
        // the node is already at front
        lru.push_front( {key, value} );
        cache[key] = lru.begin();
    }
    private:
    int cap;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
};s