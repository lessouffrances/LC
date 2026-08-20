class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) == 0: return []
        n = len(nums)
        # construct prefixProduct
        curr_product = 1
        prefix_product = [1] * n
        for i in range(1, n):
            curr_product *= nums[i-1]
            prefix_product[i] = curr_product
        
        # construct suffixProduct
        curr_product = 1
        suffix_product = [1] * n
        for i in range(n-2, -1, -1):
            curr_product *= nums[i+1]
            suffix_product[i] = curr_product
        
        res = []
        for i in range(n):
            res.append(prefix_product[i]*suffix_product[i])
        return res
        


        
        

