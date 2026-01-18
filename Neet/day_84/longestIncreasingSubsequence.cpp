class Solution
{
   public:
   int lengthOfLIS(vector<int>& nums)
   {
      if (nums.empty()) return 0;
      lookUp[0] = 1;
      
      for (int i=1; i<nums.size(); i++) {
         // look for memo
         int maxPrevLIS = 0;
         for (int idx=i-1; idx>=0; idx--) {
            if (nums[idx] < nums[i]) {
               maxPrevLIS = max(lookUp[idx], maxPrevLIS);
            }
         }
         lookUp[i] = 1 + maxPrevLIS;
      }

      int maxLIS = max_element(lookUp.begin(), lookUp.end(), [](const auto& a, const auto& b){
         return a.second < b.second;
      })->second;
      return maxLIS;
      
   }
   private:
   unordered_map<int, int> lookUp; // { idx: LIS ends with the idx }
};