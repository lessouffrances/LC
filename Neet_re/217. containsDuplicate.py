class Solution:
    def containsDuplicate(self, nums) -> bool:
        hashMap = {}

        for num in nums:
            hashMap[num] = hashMap.get(num, 0) + 1
            if hashMap[num] >= 2:
                return True
            else:
                continue
        return False

def main():
    self = Solution
    nums = [1,2,3,1]
    nums = [1,1,1,3,3,4,3,2,4,2]
    print(Solution.containsDuplicate(self, nums))
main()