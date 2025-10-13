class Solution:
    def productExceptSelf(self, nums):
        prefix = postfix = 1
        n = len(nums)
        prefixList = [1] * n
        postfixList = [1] * n
        
        for i in range(len(nums)):
            prefix = prefix * nums[i]
            prefixList[i] = prefix 
        print(prefixList)
        
        for i in range(len(nums)-1, -1, -1):
            postfix = postfix * nums[i]
            postfixList[i] = postfix
        print(postfixList)

        for i in range(len(nums)):
            if i == 0:
                nums[i] = postfixList[i+1]
            elif i == len(nums)-1:
                nums[i] = prefixList[i-1]
            else:
                nums[i] = prefixList[i-1] * postfixList[i+1]
        
        return nums

        # res = [1] * len(nums)

        # prefix = 1
        # for i in range(len(nums)):
        #     res[i] = prefix
        #     prefix *= nums[i]
        
        # postfix = 1
        # for i in range(len(nums)-1, -1, -1):
        #     res[i] *= postfix
        #     postfix *= nums[i]

        # return res

def main():
    self = Solution()
    nums = [1, 2, 3, 4]
    # nums = [-1, 1, 0, -3, 3]

    print(Solution.productExceptSelf(self, nums))

main()