class Solution 
{
    public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // seed the first pair
        pq.push( {nums1[0]+nums2[0], 0, 0} );
        set<pair<int, int>> visited;
        visited.insert( {0, 0} );

        while (!pq.empty() && k-- > 0) {
            auto top = pq.top();
            pq.pop();xw

            int sum = top[0], i = top[1], j = top[2];
            res.push_back( {nums1[i], nums2[j]} );

            // try incrementing i
            if (i+1 < nums1.size() && !visited.count( {i+1, j} )) {
                visited.insert( {i+1, j} );
                pq.push( {nums1[i+1]+nums2[j], i+1, j} );
            }
            if (j+1 < nums2.size() && !visited.count( {i, j+1} )) {
                visited.insert( {i, j+1} );
                pq.push( {nums1[i]+nums2[j+1], i, j+1} );
            }
        }
        return res;
    }
};