# This is the HashMap solution for the 3Sum problem.
from collections import Counter

class Solution:
    def threeSum(self, nums):
        nums = sorted(nums)
        print(nums)
        hashMap = dict(Counter(nums))
        tripletSeen = set()
        res = []

        for i in range(len(nums)):
            hashMap = dict(Counter(nums))
            if nums[i] in hashMap and hashMap[nums[i]] >= 1:
                hashMap[nums[i]] -= 1
            else:
                continue
            
            twoSumTarget = -nums[i]
            for j in range(i+1, len(nums)):
                if nums[j] in hashMap and hashMap[nums[j]] >= 1:
                    hashMap[nums[j]] -= 1
                else:
                    continue
                
                diff = twoSumTarget-nums[j]
                if diff in hashMap and hashMap[diff] >= 1:
                    hashMap[diff] -= 1
                    triplet = sorted([nums[i], nums[j], diff])
                    tripletTuple = tuple(triplet)
                    if tripletTuple not in tripletSeen:
                        res.append(triplet)
                        tripletSeen.add(tripletTuple)

                hashMap[nums[j]] += 1

        print(res)
        return res
    
def main():
    solution = Solution()  
    # nums = [-1, 0, 1, 0]
    nums = [2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10]
    # expected: [[-10,5,5],[-5,0,5],[-4,2,2],[-3,-2,5],[-3,1,2],[-2,0,2]]
    # nums = [0, 0, 0]
    solution.threeSum(nums)  
main()
