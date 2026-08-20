class Solution 
{
    public:
    void sortColors(vector<int>& nums) 
    {
        if (nums.empty()) return;

        vector<int> counter(3, 0);
        for (int num : nums) {
            counter[num]++;
        }

        int j = 0;
        for (int i=0; i<3; i++) {
            while (counter[i] > 0) {
                nums[j] = i;
                j++;
                counter[i]--;
            }
        }
    }
};