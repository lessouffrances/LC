class Solution:
    def maxOperations(self, nums, k: int) -> int:
        hashMap = {}
        count = 0

        for i in range(len(nums)):
            hashMap[nums[i]] = nums.count(nums[i])
        print(hashMap)

        for key in hashMap:
            diff = k-key
            if hashMap.get(key, 0) > 0 and hashMap.get(diff, 0) > 0:
                if diff == key:
                    count += (hashMap[diff]//2)

                else:
                    pair = min(hashMap[diff], hashMap[key])
                    count += pair
                    hashMap[diff] -= pair
                    hashMap[key] -= pair

        return count

def main():
    self = Solution
    nums = [1,2,3,4]
    k = 5 

    # nums = [3,1,3,4,3]
    # k = 6 # 1
    # nums = [4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4]
    # k = 2
    print(Solution.maxOperations(self, nums, k))



main()