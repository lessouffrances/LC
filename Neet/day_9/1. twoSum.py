class Solution:
    def twoSum(self, nums, target: int):
        hashMap = {}
        for i in range(len(nums)):
            hashMap[nums[i]] = i
        # print(hashMap)
            

        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in hashMap and hashMap[diff] != i:
                return [i, hashMap[diff]]
            




def main():
    self = Solution()
    # nums = [2, 7, 11, 15]
    # target = 9
    nums = [3, 2, 4]
    target = 6
    nums =  [3, 3]
    target = 6
    print(Solution.twoSum(self, nums, target))

main()





