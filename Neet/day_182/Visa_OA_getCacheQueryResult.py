# T2 — Cache Query Lookup
# Problem: Implement a cache query system. Given a cache list of (timestamp, key, value) entries, 
# and a query list of (key, timestamp) pairs, for each query find the corresponding value 
# in the cache and return all results as an integer array. 

# The problem guarantees every query entry exists in the cache.
# Approach: Iterate through the cache list, storing (key, timestamp) 
# as a dictionary key mapped to the integer value. Then iterate through queries, 
# directly extracting the answer from the dictionary. 


class Solution(object):
    # cache: (timestamp, key, value)
    # query: (key, timestamp)
    def cacheQuery(self, cache, queries):
        if not cache or not queries:
            return []

        look_up_table = {} # (key, timestamp) : value

        for timestamp, key, value in cache:
            key_timestamp = (key, timestamp)
            look_up_table[key_timestamp] = value
        
        res = []
        for q in queries:
            res.append(look_up_table[q])
        return res

