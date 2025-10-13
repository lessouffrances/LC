class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        last = m + n - 1

        while m > 0 and n > 0:
            if nums1[m - 1] > nums2[n - 1]:
                nums1[last] = nums1[m - 1]
                m -= 1
            else:
                nums1[last] = nums2[n - 1]
                n -= 1
            last -= 1
        
        while n > 0:
            nums1[last] = nums2[n - 1]
            last, n = last - 1, n - 1
        print(nums1)


        
def main():
    self = Solution()
    nums1 = [1,2,3,0,0,0]
    nums2 = [2,5,6]
    m = 3
    n = 3
    Solution.merge(self, nums1, m, nums2, n)
main()