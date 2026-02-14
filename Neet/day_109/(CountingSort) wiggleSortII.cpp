class Solution 
{
    public:
    void wiggleSort(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int>counter(maxi+1, 0);

        for (int num : nums) {
            counter[num]++;
        }

        // fill odd pos
        int j = maxi;
        for (int i=1; i<n; i+=2) {
            while (counter[j] == 0) j--;
            nums[i] = j;
            counter[j]--;
        }

        // fill even pos
        for (int i=0; i<n; i+=2) {
            while (counter[j] == 0) j--;
            nums[i] = j;
            counter[j]--;
        }
    }
};