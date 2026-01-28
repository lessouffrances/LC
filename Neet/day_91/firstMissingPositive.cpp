




// [3,4,-1,1], exp = 2
// [7,8,9,11,12], exp = 1



class Solution 
{
    public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size(); //4

        for (int i=0; i<n; i++) { //0  1  2
            if (nums[i] <= 0 || nums[i] > n) { 
                nums[i] = n + 1;
            }
        }

        // [-3,4,-5,-1]

        for (int i=0; i<n; i++) { //0  1  2  3
            int num = abs(nums[i]);
            if (num <= n) {//3<4  4<=4  5>4  1<=4
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        for (int i=0; i<n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};