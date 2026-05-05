class Solution(object):
    def threeSum(self, nums):
        if not nums or len(nums) < 3:
            return []

        # sort in-place
        nums.sort()
        n = len(nums)
        res = []

        for i in range(n-2):
            # skip duplicates
            if i > 0 and nums[i] == nums[i-1]:
                continue

            target = -nums[i]
            left = i+1
            right = n-1

            while left < right:
                two_sum = nums[left] + nums[right]
                if two_sum < target:
                    left += 1
                elif two_sum > target:
                    right -= 1
                else:
                    # find a valid triplet
                    res.append( [nums[i], nums[left], nums[right]] )
                    # take one step
                    left, right = left+1, right-1

                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                    while left < right and nums[right] == nums[right+1]:
                        right -= 1
            
        return res