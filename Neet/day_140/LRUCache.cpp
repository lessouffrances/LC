class LRUCache 
{
    public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) 
    {
        // need to put this key/value at front
        if (cache.count(key)) {
            lru.splice(lru.begin(), lru, cache[key]);
            return lru.begin()->second; // return the val
        }
        // if the key is not in cache
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (cache.count(key)) {
            lru.splice(lru.begin(), lru, cache[key]);
            lru.begin()->second = value;
            cache[key] = lru.begin();
            return;
        }

        // if new key/value pair
        // check for cap
        if (lru.size() == cap) {
            // remove the least recent use
            int keyToDelete = lru.back().first;
            lru.pop_back();
            cache.erase(keyToDelete);
        }

        lru.push_front( {key, value} );
        cache[key] = lru.begin();
    }
    private:
    int cap;
    list<pair<int, int>> lru; // key : value
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
};
    
   