class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        last = m + n - 1

        # merge in reserse order
        while m > 0 and n > 0:
            if nums1[m - 1] > nums2[n - 1]:
                nums1[last] = nums1[m - 1]
                m -= 1
            else: 
                nums1[last] = nums2[n - 1]
                n -= 1
            last -= 1
        
        # fill nums1 with left over elements in nums2
        while n > 0:
            nums1[last] = nums2[n - 1]
            n, last = n - 1, last - 1
        print(nums1)


def main():       
    nums1 = [2, 3, 4, 0, 0, 0] # m as pointer
    nums2 = [2, 5, 6]          # n as pointer
           
    self = Solution()
    Solution.merge(self, nums1, 3, nums2, 3)

main()