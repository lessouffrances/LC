class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0: return []
        self.res = []
        self.dfs(0, [], nums)
        return self.res

    def dfs(self, curr_idx, curr_path, nums):
        if curr_idx == len(nums):
            self.res.append(curr_path[:])
            return
        
        # take this idx
        curr_path.append(nums[curr_idx])
        self.dfs(curr_idx+1, curr_path, nums)
        curr_path.pop()
        # skip
        self.dfs(curr_idx+1, curr_path, nums)