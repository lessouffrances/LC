class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]):
        nums1Index = {n:i for i, n in enumerate(nums1)}
        print(nums1Index)
        res = [-1] * len(nums1)

        for i in range(len(nums2)):
            if nums2[i] not in nums1Index:
                continue
            for j in range(i + 1, len(nums2)):
                if nums2[j] > nums2[i]:
                    index = nums1Index[nums2[i]]
                    res[index] = nums2[j]
                    break
        print(res)
        return res
                    
def main():
    self = Solution()
    nums1 = [2,4]
    nums2 = [1,2,3,4]
    # output = [3, -1]
    # approach 1 :
    # num |  index(num) | range(index(num), len(nums2)) | > 

    # approach 2:
    # numsIdex = {2:0 ,  4:1}
    # res = [-1, -1]
    # res = [4, ]
    Solution.nextGreaterElement(self, nums1, nums2)
main()