class LRUCache 
{
    public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }

    int get(int key) 
    {
        if (cache.count(key)) {
            lru.splice(lru.begin(), lru, cache[key]);
            return lru.begin()->second;
        } 
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (cache.count(key)) {
            lru.splice(lru.begin(), lru, cache[key]);
            lru.begin()->second = value;
            return;
        }
        
        if (lru.size() == capacity) {
            // remove the least recent used
            int keyToRemove = lru.back().first;
            cache.erase(keyToRemove);
            lru.pop_back();
        }

        lru.push_front( {key, value} );
        cache[key] = lru.begin();
        return;
    }
    private:
    int capacity;
    list<pair<int, int>> lru; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> cache;
};
    
   