// The least recent used function needs this container to be dynamic
// use splice from list, splice(iterator endPos, list& l, iterator iter)
// to get the iterator for the list, we use map, key => list::iterator

// {1,3} <-> {2,12} <-> {3,13} <-> {4,0}
// map = { ... {key, list::iter} ... }
// the map allows to grab some key/value pair in O(1), 
// and the list in C++ allows splice, put the element upfront, 
// preserving the relative order of the remaining list

class LRUCache 
{
    public:
    LRUCache(int capacity) 
    {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if (cache.count(key)) {
            // do the splice
            lru.splice(lru.begin(), lru, cache[key]);
            // return the value associated with the key
            return lru.begin()->second;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (cache.count(key)) {
            // and splice -> extract the data upfront
            lru.splice(lru.begin(), lru, cache[key]);
            lru.begin()->second = value;
            return;
        }

        // about to exceed the cap
        if (lru.size() == cap) {
            // release the lru one
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
    list<pair<int, int>> lru; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache; // {key, iterator of the data in the list }
};
    
   