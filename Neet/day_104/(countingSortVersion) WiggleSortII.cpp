class Solution 
{
    public:
    void wiggleSort(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        // counting Sort
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> numCounter(maxNum+1);
        for (int num : nums) {
            numCounter[num]++;
        }

        // iterate thru odd-pos: put greater numbers
        int j = maxNum;
        for (int i=1; i<n; i+=2) {
            while (numCounter[j] == 0) j--;
            nums[i] = j;
            numCounter[j]--;
        }
        // iterate thru even-pos: put smaller numbers
        for (int i=0; i<n; i+=2) {
            while (numCounter[j] == 0) j--;
            nums[i] = j;
            numCounter[j]--;
        }
    }
};