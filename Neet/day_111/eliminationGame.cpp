class Solution 
{
public:
    int lastRemaining(int n) 
    {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {  
            nums.push_back(i);
        }

        int round = 0;
        while (nums.size() > 1) {
            if (round % 2 == 0) {
                nums = eliminate(nums, true);
            } else {
                nums = eliminate(nums, false);
            }
            round++;
        }
        return nums[0];
    }

private:
    vector<int> eliminate(vector<int>& arr, bool fromLeft) 
    {
        vector<int> res;
        int n = arr.size();

        if (fromLeft) {
            for (int i=1; i<n; i+=2) {
                res.push_back(arr[i]);
            }
        } else {
            int start = (n % 2 == 0) ? 0 : 1;
            for (int i = start; i < n; i += 2) {
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};