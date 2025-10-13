class Solution:
    def nextGreaterElement(self, nums1, nums2):
        res = []
        
        for num in nums1:
            index = nums2.index(num)
            if index+1 > len(nums2):
                res.append(-1)
            else:
                appended = False
                for greaterNum in nums2[index+1: ]:
                    if greaterNum > num:
                        appended = True
                        res.append(greaterNum)
                        break
                if appended != True:
                    res.append(-1)

        print(res)
        return res


def main():
    self = Solution
    nums1 = [4,1,2]
    nums2 = [1,3,4,2] # output = [-1, 3, -1]

    Solution.nextGreaterElement(self, nums1, nums2)
main()
        
        