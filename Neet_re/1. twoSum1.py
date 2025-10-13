class Solution:
    def twoSum(self, nums, target: int):
        hashMap = {}
        for i, num in enumerate(nums):
            hashMap[num] = i
        print(hashMap)

        res = []
        for i, num in enumerate(nums):
            diff = target-num
            if diff in hashMap and hashMap[diff] != i:
                res.append(i)
                res.append(hashMap[diff])
                print(res)
                break
        return res

                
    

def main():
    self = Solution
    nums = [2,7,11,15]
    target = 9
    nums = [3, 3]
    target = 6
    Solution.twoSum(self, nums, target)
main()