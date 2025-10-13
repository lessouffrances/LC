class Solution:
    def maxOperations(self, nums, k: int) -> int:
        hashMap = {}
        count = 0

        for num in nums:
            hashMap[num] = hashMap.get(num, 0)+1
        
        for key in hashMap:
            diff = k-key
            if hashMap.get(key, 0)>0 and hashMap.get(diff, 0)>0:
                if diff == key:
                    count += (hashMap[diff]//2)
                else:
                    pair = min(hashMap[diff], hashMap[key])
                    count += pair
                    hashMap[diff] -= pair
                    hashMap[key] -= pair
        print(count)
        return count

def main():
    self = Solution
    nums = [1,2,3,4]
    k = 5
    Solution.maxOperations(self, nums, k)
main()