class LRUCache
{
    private:
    int cap;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

    public:
    LRUCache(int capacity) : cap(capacity) {}

    void put (int key, int value) {
        if (cache.count(key)) {
            cache[key]->second = value;
            lru.splice(lru.begin(), lru, cache[key]);
            return;
        }

        // check cap
        if (lru.size() == cap) {
            // need to remove the least recently used one
            int lruKey = lru.back().first;
            lru.pop_back();
            cache.erase(lruKey);
        }
        lru.push_front( {key, value} );
        cache[key] = lru.begin();
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        lru.splice(lru.begin(), lru, cache[key]);
        return cache[key]->second;
    }
};