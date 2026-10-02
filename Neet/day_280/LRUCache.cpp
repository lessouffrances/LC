
// maintain the thing by LL

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
        // put this unit upfront in the LL
        lru.splice(lru.begin(), lru, iter);
        // return the value
        return lru.begin()->second;
    }
    
    void put(int key, int value) 
    {
        // if it is for substitute value
        if (cache.count(key)) {
            auto iter = cache[key];
            lru.splice(lru.begin(), lru, iter);
            lru.begin()->second = value;
            return;
        }
        // if cap full, need to release the LRU one
        if (lru.size() == cap) {
            int keyToErase = lru.back().first;
            cache.erase(keyToErase);
            lru.pop_back();
        }

        lru.push_front( {key, value} );
        cache[key] = lru.begin();
        return;
    }

    private:
    int cap;
    list<pair<int, int>> lru; // { key, value }
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
};