class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]):
        lst = []
        for num in nums1:
            index = nums2.index(num)
            rightSub = nums2[index+1 :]
            
            n = 0
            for right in rightSub:
                if right > num and n < 1:
                    lst.append(right)
                    n += 1
                    break
            
            if n < 1: # if no greater is found
                lst.append(-1)
                    

        print(lst)
        return lst
                    

def main():
    self = Solution()
    # nums1 = [2,4]
    # nums2 = [1,2,3,4]
    nums1 = [4,1,2] 
    nums2 = [1,3,4,2]
    # output = [-1, 3, -1]
    Solution.nextGreaterElement(self, nums1, nums2)
main()