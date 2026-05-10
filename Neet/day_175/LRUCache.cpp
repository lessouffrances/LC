class LRUCache 
{
    public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) 
    {
        if (cache.count(key)) {
            lru.splice(lru.begin(), lru, cache[key]);
            return lru.begin()->second;
        }
        // if the key is not in the cache
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
            int keyToDelete = lru.back().first;
            lru.pop_back();
            cache.erase(keyToDelete);
        }

        lru.push_front( {key, value} );
        cache[key] = lru.begin();
        return;
    }

    private:
    int capacity;
    list<pair<int, int>> lru; // key : val
    // key will point to the iterator for that data 
    unordered_map<int, list<pair<int, int>>::iterator> cache; 
};


// "The core challenge here is achieving O(1) for both get and put. 
// A hash map alone gives us O(1) lookup, but doesn't track recency. 
// A linked list tracks recency — most recent at the front, 
// least recent at the back — but gives O(N) lookup. So I combine both: 
// a doubly linked list for order, and a hash map that maps each key 
// directly to its node's iterator in the list.
// For get, I check the hash map. If the key exists, 
// I splice that node to the front of the list 
// — which is O(1) because I have a direct pointer to it 
// — and return its value. If it doesn't exist, I return -1.
// For put, if the key already exists, I splice it to the front 
// and update its value. If it's a new key and we're at capacity, 
// I evict by reading the key from the back of the list, popping it, 
// and erasing it from the hash map. Then I push the new key-value pair to the front 
// and store its iterator in the hash map.
// The key insight is that list::splice doesn't invalidate iterators 
// — it just rewires pointers — so the hash map entries remain valid after any reordering. 
// This gives us true O(1) for both operations."