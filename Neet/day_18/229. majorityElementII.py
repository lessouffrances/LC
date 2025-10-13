from collections import Counter
class Solution:
    def majorityElement(self, nums):
        freq = len(nums)/3
        counter = Counter(nums)
        print(counter)
        res = []
        for key, value in counter.items():
            if value > freq:
                res.append(key)
        print(res)
        return res


        
        
    



def main():
    self = Solution
    nums = [3,2,3]
    # nums = [1]
    # nums = [1,2]
    Solution.majorityElement(self, nums)
main()