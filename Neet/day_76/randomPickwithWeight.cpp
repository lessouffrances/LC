class Solution 
{
public:
   vector<int> prefixSum;
   int totalSum = 0;
   Solution(vector<int>& w)
   {
      for (int weight : w) {
         totalSum += weight;
         prefixSum.push_back(totalSum);
      }  
   }
    
   int pickIndex()
   {
      int target = rand() % totalSum;
      // find the first index where prefixSum[i] > target
      int left = 0, right = prefixSum.size()-1;
      while (left < right) {
         int mid = (left + (right - left)) / 2;
         if (prefixSum[mid] <= target) {
            left = mid + 1;
         } else {
            right = mid;
         }
      }
      return left; 
   }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
