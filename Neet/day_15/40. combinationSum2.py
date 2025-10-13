class Solution:
    def combinationSum2(self, candidates, target: int):
        res = []
        candidates.sort()

        def dfs(i, curr, total):
            if total == target:
                res.append(curr.copy())
                return
            if total > target or i == len(candidates):
                return
            
            # include candidates[i]
            curr.append(candidates[i])
            dfs(i+1, curr, total+candidates[i])
            curr.pop()

            # skip candidates[i]
            while i+1 < len(candidates) and candidates[i] == candidates[i+1]:
                i += 1
            dfs(i+1, curr, total)
        
        dfs(0, [], 0)
        return res
        

def main():
    self = Solution
    candidates = [10,1,2,7,6,1,5]
    target = 8
    candidates = [2,5,2,1,2]
    target = 5
    Solution.combinationSum2(self, candidates, target)
main()