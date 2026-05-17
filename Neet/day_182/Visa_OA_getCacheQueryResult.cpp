// T2 — Cache Query Lookup
// Problem: Implement a cache query system. Given a cache list of (timestamp, key, value) entries, 
// and a query list of (key, timestamp) pairs, for each query find the corresponding value 
// in the cache and return all results as an integer array. 

// The problem guarantees every query entry exists in the cache.
// Approach: Iterate through the cache list, storing (key, timestamp) 
// as a dictionary key mapped to the integer value. Then iterate through queries, 
// directly extracting the answer from the dictionary. 

#include <vector>
#include <map>
#include <tuple>
using namespace std;

class Solution {
    public:
    // cache: (timestamp, key, value)
    // query: (key, timestamp)
    vector<int> cacheQuery(vector<tuple<int,int,int>>& cache, 
        vector<pair<int,int>>& queries) {
        if (cache.empty() || queries.empty()) return {};
        
        map<pair<int,int>, int> lookup;

        for (auto& [timestamp, key, value] : cache) {
            lookup[{key, timestamp}] = value;
        }

        vector<int> res;
        for (auto& [key, timestamp] : queries) {
            res.push_back(lookup[{key, timestamp}]);
        }
        return res;
    }
};