











class Solution 
{
    public:
    void wiggleSort(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();
        
        // even-pos should <= next and odd-pos shoule >= next
        for (int i=0; i<n-1; i++) {
            if ((i % 2 == 0 && nums[i] > nums[i+1]) || (i % 2 != 0 && nums[i] < nums[i+1])) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
};