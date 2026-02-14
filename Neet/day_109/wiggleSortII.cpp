class Solution 
{
    public:
    void wiggleSort(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        vector<int>sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());

        int mid = (n-1) / 2; 
        // use the larger half to fill the odd-pos
        int oddPos = 1, evenPos = 0;
        for (int i=n-1; i>mid; i--) {
            nums[oddPos] = sortedNums[i];
            oddPos+=2;
        }
        for (int i=mid; i>=0; i--) {
            nums[evenPos] = sortedNums[i];
            evenPos+=2;
        }
    }
};