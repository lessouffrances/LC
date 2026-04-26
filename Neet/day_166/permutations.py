class Solution(object):
    def permute(self, nums):
        if not nums:
            return

        self.res = []
        self.dfs(0, nums)
        return self.res

    def dfs(self, start, nums):
        if start == len(nums):
            self.res.append(nums[:])
            return
        
        for i in range(start, len(nums)):
            nums[start], nums[i] = nums[i], nums[start]
            self.dfs(start+1, nums)
            nums[start], nums[i] = nums[i], nums[start]

        