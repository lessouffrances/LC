# T: O(N)
# S: O(k)

from collections import deque

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        if not nums:
            return []
        
        dq = deque()
        n = len(nums)
        res = []
        for i in range(n):
            # pop the element out of the curr window
            if dq and dq[0] < i-k+1:
                dq.popleft()
            
            while dq and nums[i] > nums[dq[-1]]:
                dq.pop()
            dq.append(i)

            if i >= k-1:
                res.append(nums[dq[0]])
        return res


        
        