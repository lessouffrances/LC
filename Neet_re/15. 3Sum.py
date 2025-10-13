class Solution:
    def threeSum(self, nums):
        nums.sort()
        res = []

        for i, num in enumerate(nums):
            if (i-1)>=0 and nums[i] == nums[i-1]:
                continue

            diff = 0-num
            l, r = i+1, len(nums)-1
            while l<r:
                sum = nums[l]+nums[r]
                if sum<diff:
                    l+=1
                elif sum>diff:
                    r-=1
                else:
                    res.append([num, nums[l], nums[r]])
                    l+=1
                    r-=1
                    while l<r and nums[l] == nums[l-1]:
                        l += 1
                    while l<r and nums[r] == nums[+1]:
                        r -= 1
        print(res)
        return res

        


def main():
    self = Solution
    nums = [-1,0,1,2,-1,-4]
    # output = [[-1,-1,2], [-1,0,1]]
    Solution.threeSum(self, nums)
main()