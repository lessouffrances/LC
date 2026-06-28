class Solution 
{
    public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right-left)/2;
            if (isBelowThreshold(mid, nums, threshold)) {
                // can be lower
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    bool isBelowThreshold(int divisor, vector<int>& nums, int threshold) 
    {
        int total = 0;
        for (int& num : nums) {
            total += (num + divisor - 1) / divisor;
        }
        return total <= threshold;
    }
};