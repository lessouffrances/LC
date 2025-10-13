class Solution:
    def removeElement(self, nums, val: int) -> int:
        for i in range(len(nums)-1):
            while nums[i] == val:
                nums[i: len(nums)-1] = nums[i+1:]
                nums[-1] = ''
            
            if nums[i] == '':
                return i
            i += 1
        
def main():
    self = Solution
    nums = [0, 1, 2, 2, 3, 0, 4, 2]
    val = 2
    print(Solution.removeElement(self, nums, val))
main()