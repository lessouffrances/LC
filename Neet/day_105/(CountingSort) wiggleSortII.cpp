









class Solution 
{
   public:
   void wiggleSort(vector<int>& nums) 
   {
       if (nums.empty()) return;
       int n = nums.size();

       int maxi = *max_element(nums.begin(), nums.end());
       vector<int> numsCounter(maxi+1, 0);

       for (int num : nums) {
           numsCounter[num]++;
       }

       // odd-pos should have larger numbers
       int j = maxi;
       for (int i=1; i<n; i+=2) {
           while (numsCounter[j] == 0) j--;
           nums[i] = j;
           numsCounter[j]--;
       }

       for (int i=0; i<n; i+=2) {
           while (numsCounter[j] == 0) j--;
           nums[i] = j;
           numsCounter[j]--;
       }
   }
};