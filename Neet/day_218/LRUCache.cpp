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
        // splice template: .splice(_1_, _2_, _3_) 
        // 1: where does this node land?
        // 2: from where? which LL?
        // 3: which iterator?
        lru.splice(lru.begin(), lru, iter);
        return lru.begin()->second;
    }
    
    // LRU: because we need to put a new KV pair and there's constraint
    // so we always need to maintain a sequence of which one is most used to least used
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
    unordered_map<int, list<pair<int, int>>::iterator> cache; // for O(1) retrieval
    list<pair<int, int>> lru; // maintain sequence
    // once we do something on key, 
    // need to splice the LL: extract the node and put it upfront
};
    