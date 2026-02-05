











// [3,3,5,5,6,7]
//              i
// nums = [1,3,-1,-3,5,3,6,7], k = 3
// deque = [1,2]



class Solution 
{
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<int> res;
        deque<int> dq;
        for (int i=0; i<n; i++) {//0 1 2
            // remove idxes outside the window
            if (!dq.empty() && dq.front() < i-k+1) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);//0 1 2

            if (i >= k-1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};