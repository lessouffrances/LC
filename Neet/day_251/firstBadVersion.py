# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """

        # find the leftmost isBadVersion(version) returns True
        left, right = 1, n
        res = -1

        while left <= right:
            mid = (left + right) // 2
            if isBadVersion(mid) == True:
                res = mid
                right = mid-1
            else:
                left = mid+1
        return res
            
