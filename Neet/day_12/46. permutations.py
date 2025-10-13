class Solution:
    def permute(self, nums):
        res = []

        if len(nums) == 1:
            return [nums[:]]
        
        for i in range(len(nums)):
            n = nums.pop(0)
            perms = self.permute(nums)

            for perm in perms:
                perm.append(n)
            res.extend(perms)
            nums.append(n)
        
        return res
        
def main():
    self = Solution()
    nums = [1, 2, 3]
    print(Solution.permute(self, nums))
main()