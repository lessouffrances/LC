class Solution:
    def singleNumber(self, nums) -> int:
        hashMap = {}

        for num in nums:
            hashMap[num] = hashMap.get(num, 0) + 1
        
        hashMap = dict(sorted(hashMap.items(), key=lambda item: item[1]))
        keyList = list(hashMap.keys())
        
        return keyList[0]

        

        





def main():
    self = Solution
    nums = [2,2,1]
    # nums = [4,1,2,1,2]
    # nums = [1]
    print(Solution.singleNumber(self, nums))
main()