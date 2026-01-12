#include <vector>
#include <cstdio>

class Solution 
{
    private:
    void printVec(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (i == n-1) {
                printf("%d\n", nums[i]);
            } else {
                printf("%d ", nums[i]);
            }
        }
    }

    public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (nums.empty()) return -1;

        int n = nums.size();
        int res = 0;
        for (int start=0; start<n; start++) {
            long long product = 1;
            for (int end=start; end<n; end++) {
                product *= nums[end];
                if ((int)product < k) {
                    res++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
