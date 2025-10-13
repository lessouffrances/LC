class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        majorCount = len(nums) // 2 # >
        print(majorCount)
        
        hashMap = {}
        
        for num in nums:
            hashMap[num] = 1 + hashMap.get(num, 0)
        print(hashMap)
        
        for num in hashMap:
            if hashMap[num] > majorCount:
                return num
        
def main():
    self = Solution()
    # nums = [2,2,1,1,1,2,2]
    # nums = [3,2,3]
    nums = [3,3,4]
    print(Solution.majorityElement(self, nums))
main()