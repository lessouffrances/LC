class Solution:
    def twoSum(self, nums, target: int):
        res = []
        hashMap = {}

        for i, num in enumerate(nums):
            hashMap[num] = i
        print("initial hashMap: ", hashMap, end="\n\n")

        for i, num in enumerate(nums):
            diff = target-num
            if diff in hashMap and hashMap[diff] != i:
                res.append(i)
                res.append(hashMap[diff])
                break
        return res

            


def main():
    self = Solution
    nums = [2,7,11,15] 
    target = 9
    Solution.twoSum(self, nums, target)
main()