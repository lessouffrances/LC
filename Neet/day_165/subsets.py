class Solution(object):
    def subsets(self, nums):
        self.res = []
        self.dfs(0, [], nums)
        return self.res

    def dfs(self, currIdx, currPath, nums):
        if currIdx == len(nums):
            self.res.append(currPath[:]) # need shallow copy
            return
        
        # take
        currPath.append(nums[currIdx])
        self.dfs(currIdx+1, currPath, nums)
        currPath.pop()

        # skip
        self.dfs(currIdx+1, currPath, nums)    