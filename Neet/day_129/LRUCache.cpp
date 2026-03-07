class LRUCache 
{
    public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) // => hashMap
    {
        // need to put this key/value at front
        if (cache.count(key)) {
            // put the key/value pair with the key upfront in the LL
            lru.splice(lru.begin(), lru, cache[key]);
            return lru.begin()->second;
        }

        return -1;
    }
    void put(int key, int value)  // => hashMap
    {
        // need to put this key/value at front
        if (cache.count(key)) {
            // put the key/value pair with the key upfront in the LL
            lru.splice(lru.begin(), lru, cache[key]);
            cache[key] = lru.begin();
            lru.begin()->second = value;
            return; // important return
        }

        // need to check cap
        if (lru.size() == cap) {
            // need to delete the most inactive one: at the back of lru
            int toDeleteKey = lru.back().first;
            lru.pop_back();
            cache.erase(toDeleteKey);
        }

        // cap is safe
        lru.push_front( {key, value} );
        cache[key] = lru.begin();
    }

    // function: put the LRU at front of some (sequence)? 

    private:
    int cap;
    list<pair<int, int>> lru; // key/value
    unordered_map<int, list<pair<int, int>>::iterator> cache;
};
    
   