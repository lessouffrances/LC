
// double-ended queue
class Solution 
{
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<int> res;
        deque<int> dq;

        for (int i=0; i<n; i++) {
            // if the front of the deque is out of k-consideration
            if (!dq.empty() && dq.front() < i-k+1) {
                dq.pop_front();
            }

            // only preserve the max
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k-1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};