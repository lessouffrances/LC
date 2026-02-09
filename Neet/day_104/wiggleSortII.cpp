







// O(n) space, and O(n logn) time
class Solution 
{
    public:
    void wiggleSort(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        vector<int>sortedNums(nums); //O(n)
        sort(sortedNums.begin(), sortedNums.end()); //O(nlogn)
        int mid = (n-1) / 2;
        int right = n-1;

        for (int i=0; i<n; i++) {
            if (i % 2 != 0) {
                nums[i] = sortedNums[right];
                right--;
            } else {
                nums[i] = sortedNums[mid];
                mid--;
            }
        }
    }
};