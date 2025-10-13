class Solution:
    def combine(self, n: int, k: int):
        res = []

        def backTrack(start, combination):
            if len(combination) == k:
                res.append(combination.copy())
                return
            
            for i in range(start, n+1):
                combination.append(i)
                backTrack(i+1, combination)
                combination.pop()
        
        backTrack(1, [])
        return res

def main():
    self = Solution()
    n = 4
    k = 2
    print(Solution.combine(self, n, k))

main()