class Solution 
{
public:
   vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
   {
      if (nums1.empty() || nums2.empty()) return {};
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

      pq.push( {nums1[0]+nums2[0], 0, 0} );
      set<pair<int, int>> visited;
      visited.insert( {0, 0} );
      vector<vector<int>> res;

      while (k>0 && !pq.empty()) {
         auto [sum, i, j] = pq.top();
         pq.pop();
         res.push_back( {nums1[i], nums2[j]} );
  
         if (i+1 < nums1.size() && !visited.cout( {i+1, j} )) {
            pq.push( {nums1[i+1]+nums2[j], i+1, j} );
            visited.push( {i+1, j} );
         }

         if (j+1 < nums2.size() && !visited.count( {i, j+1 })) {
            pq.push( {nums1[i]+nums2[j+1], i, j+1} );
            visited.push( {i, j+1} );
         }
         k--;
      }
      return res;
   }
};
