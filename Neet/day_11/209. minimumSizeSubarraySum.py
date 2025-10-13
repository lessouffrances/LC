class Solution:
    def minSubArrayLen(self, target: int, nums) -> int:
        l, total = 0, 0
        res = float("inf")

        for r in range(len(nums)):
            total += nums[r]

            while total >= target:
                res = min(r-l+1, res)
                total -= nums[l]
                l += 1
            
        return 0 if res == float("inf") else res
    
        # My unverified approach:
        # nums.sort()
        # numsSet = set(nums)
        # if target in numsSet:
        #     return 1
        
        # for i in range(len(nums)):
        #     if target - nums[i] < 0 and (i - 1) >= 0:
        #         r, l = i-1, i-1
        #         break
        
        # while l >= 0:
        #     if sum[l: r+1] == target:
        #         return r+1-l
        #     l -= 1
        
        # return 0


def main():
    self = Solution()
    nums = [2, 3, 1, 2, 4, 3]
    # nums = [1, 2, 2, 3, 3, 4]
    target = 7
    print(Solution.minSubArrayLen(self, target, nums))

main()