







class Solution 
{
    public:
    void wiggleSort(vector<int>& nums) 
    {
        if (nums.empty()) return;

        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        int n = nums.size();

        int right = n-1;
        int mid = (n-1) / 2;

        // wiggle sort requires the even-pos are smallers, and odd-pos are largers
        // use the second half to fill the odd-pos 

        for (int i=1; i<n; i+=2) {
            nums[i] = sortedNums[right];
            right--;

        }
        // use the first half to fill the even-pos 
        for (int i=0; i<n; i+=2) {
            nums[i] = sortedNums[mid];
            mid--;
        }
    }
};