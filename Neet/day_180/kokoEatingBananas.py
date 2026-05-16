class Solution(object):
    def minEatingSpeed(self, piles, h):
        if not piles:
            return 0
        
        left = 1
        right = max(piles)
        while left < right:
            k = (left + right) // 2
            if self.canFinishAll(piles, h, k):
                right = k
            else:
                left = k+1

        return left

    def canFinishAll(self, piles, h, k):
        if not piles:
            return True

        n = len(piles)
        total_hours_needed = 0
        for i in range(n):
            total_hours_needed += (piles[i]+k-1) // k;
        return True if total_hours_needed <= h else False

        