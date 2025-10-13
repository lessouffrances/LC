class Solution:
    def summaryRanges(self, nums):
        lst = []
        if len(nums) == 1:
            lst.append(str(nums[0]))
            return lst
        
        l, r = 0, 1
        left = int

        nums = nums + [0]
        while r < len(nums):
            if nums[r] - nums[r-1] == 1:
                r += 1
                left = nums[l]
            else:
                if left == int:
                    lst.append(str(nums[l]))
                else:
                    lst.append(str(left) + "->" + str(nums[r-1]))
                    left = int
                r += 1
                l = r-1
            return lst

        



def main():
    self = Solution
    nums = [0,2,3,4,6,8,9]
    print(Solution.summaryRanges(self, nums))
    


main()