class LRUCache 
{
    public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) 
    {
        if (cache.count(key)) {
            // put the iterator upfront
            // physically change the LL
            lru.splice(lru.begin(), lru, cache[key]);
            // change the map
            cache[key] = lru.begin();
            return lru.begin()->second;
        }
        // the key is invalid
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (cache.count(key)) {
            // put the iterator upfront
            lru.splice(lru.begin(), lru, cache[key]);
            lru.begin()->second = value;
            cache[key] = lru.begin();
            return;
        }

        // if new key/value pair
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
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
};