# Whenever there is a comparation, consider binarySearch
from collections import Counter
class Solution:
    def numSmallerByFrequency(self, queries, words):
        res = []
        wordsFreq = []
        for word in words:
            wordsFreq.append(Solution.smallestFrequency(self, word))
        wordsFreq = sorted(wordsFreq)
        print(wordsFreq)
            
        for query in queries:
            querySmallestFreq = Solution.smallestFrequency(self, query)
            element = Solution.binaryCountGreater(self, querySmallestFreq, wordsFreq)
            res.append(element)
        return res
    
    def smallestFrequency(self, string):
        lst = list(string)
        lst = sorted(lst)
        smallestLexigraphicalChar = lst[0]
        counter = Counter(lst)
        return counter[smallestLexigraphicalChar]
  
    def binaryCountGreater(self, num, nums):
         # Binary search to find the first element greater than `num`
        l, r = 0, len(nums)
        
        while l<r:
            mid = (l+r)//2
            if nums[mid] <= num:
                l = mid + 1  # Move right to find greater values
            else:
                r = mid  # Narrow down to the left
    
        # `left` is now the index of the first element greater than `num`
        return len(nums) - l
    
    def binaryCountSmaller(self, num, nums):
        # Binary search to find the first element not smaller than `num`
        l, r = 0, len(nums)
        while l<r:
            mid = (l+r) // 2
            if nums[mid] < num:
                l = mid + 1  # Move right to find larger or equal values
            else:
                r = mid  # Narrow down to the left
        # `left` is now the index of the first element not smaller than `num`
        return l

        
def main():
    self = Solution
    print(Solution.binaryCountGreater(self, 5, [0, 1, 2, 3, 4, 6, 7]))
    print(Solution.binaryCountSmaller(self, 7, [1, 1, 1, 2, 3, 4, 5, 6, 8]))
    # Solution.numSmallerByFrequency(self, queries, words)
    # Solution.smallestFrequency(self, "vhgfajicc")
main()