








// nums = [1,3,4,2,2]

class Solution 
{
    public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size(); //5
        int left = 1, right = n-1; //4

        while (left < right) {
            int mid = left + (right - left) / 2; //2
            int count = 0;
            for (int num : nums) {
                if (num <= mid) { 
                    count++;
                }
            }
            if (count > mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};