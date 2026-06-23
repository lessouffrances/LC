class Solution 
{
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> dq;
        vector<int> res;
        int n = nums.size();

        if (n < k) return {};

        for (int i=0; i<n; i++) {
            // if out of window
            if (!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }

            // maintain a maxDq
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // start to push to res
            if (i >= k-1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};