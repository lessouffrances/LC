class Solution:
    def singleNumber(self, nums) -> int:
        hashMap = {}
        for num in nums:
            hashMap[num] = hashMap.get(num, 0) + 1
        
        for key in hashMap:
            if hashMap[key] == 1:
                return key
            
def main():
    self = Solution
    # nums = [0,1,0,1,0,1,99]
    nums = [2,2,3,2]
    print(Solution.singleNumber(self, nums))
main()