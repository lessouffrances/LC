class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        if len(nums) <= 1:
            return nums
        
        left, right = 0, len(nums)-1
        mid = (left + right) // 2
        leftHalf = self.sortArray(nums[0 : mid+1])
        rightHalf = self.sortArray(nums[mid+1 : ])

        return self.merge(leftHalf, rightHalf)

    
    def merge(self, nums1, nums2):
        """
        :type nums1: List[int], nums2: List[int]
        :rtype: List[int]
        """
        if len(nums1) == 0: return nums2
        if len(nums2) == 0: return nums1

        i, j = 0, 0
        m, n = len(nums1), len(nums2)

        res = []
        while i < m and j < n:
            if nums1[i] < nums2[j]:
                res.append(nums1[i])
                i += 1
            else:
                res.append(nums2[j])
                j += 1

        while i < m:
            res.append(nums1[i])
            i += 1

        while j < n:
            res.append(nums2[j])
            j += 1
        return res
