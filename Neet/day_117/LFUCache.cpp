class LFUCache 
{
    public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}

    int get(int key) 
    {
        if (!keyToVal.count(key)) return -1;
        increaseFreq(key);
        return keyToVal[key];
        
    }
    
    void put(int key, int value) 
    {
        if (cap <= 0) return;
        if (keyToVal.count(key)) {
            keyToVal[key] = value;
            increaseFreq(key);
            return;
        }

        if (keyToVal.size() == cap) evict();
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
    private:
    int cap, minFreq;
    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;

    void evict() 
    {
        int key = freqToKeys[minFreq].back();
        freqToKeys[minFreq].pop_back();
        if (freqToKeys[minFreq].empty()) {
            freqToKeys.erase(minFreq);
        }
        keyToVal.erase(key);
        keyToFreq.erase(key);
        keyToIter.erase(key);
    }

    void increaseFreq(int key)
    {
        int freq = keyToFreq[key];
        keyToFreq[key]++;

        freqToKeys[freq].erase(keyToIter[key]);
        freqToKeys[freq+1].push_front(key);
        keyToIter[key] = freqToKeys[freq+1].begin();

        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }
    }
};
    
   