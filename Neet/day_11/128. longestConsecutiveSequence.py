class Solution:
    def longestConsecutive(self, nums) -> int:
        numSet = set(nums)
        longest = 0

        for num in nums:
            # check if its the start of a sequence
            if (num-1) not in numSet:
                length = 0
                while (num+length) in numSet:
                    length += 1

                longest = max(length, longest)
        
        return longest
    
def main():
    self = Solution()
    nums = [0,3,7,2,5,8,4,6,0,1]
    print(Solution.longestConsecutive(self, nums))

main()