class LRUCache 
{
    public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) 
    {
        if (!cache.count(key)) return -1;
        // *the line that put the node with key at front
        lru.splice(lru.begin(), lru, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) 
    {
        // if exists: update
        if (cache.count(key)) {
            cache[key]->second = value;
            lru.splice(lru.begin(), lru, cache[key]);
            return;
        }
        
        // if no: check cap 
        if (lru.size() == cap) {
            // if about to exceed the cap
            // need to remove the lru
            int lruKey = lru.rbegin()->first;
            lru.pop_back();
            cache.erase(lruKey);
        }

        lru.push_front( {key, value} );
        // save the pointer in cache
        cache[key] = lru.begin();
    }

    private:
    int cap;
    list<pair<int, int>> lru; // a doubly-linked list that carries pair<int, int> as data
    unordered_map<int, list<pair<int, int>>::iterator> lru; // lookUp map
    // cache: { key : pointer }
};