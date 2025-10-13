class Solution:
    def maxOperations(self, nums, k: int) -> int:
        hashMap = {}
        res = 0

        for num in nums:
            if num in hashMap:
                hashMap[num] += 1
            else:
                hashMap[num] = 1
        
        print(hashMap)

        for num in nums:
            diff = k-num
            if (diff in hashMap) and (diff != num):
                while hashMap[diff] >= 1 and hashMap[num] >= 1:
                    hashMap[diff] -= 1
                    hashMap[num] -= 1
                    res += 1
            elif (diff in hashMap) and (diff == num) and (hashMap[diff] >= 2):
                pairs = hashMap[diff] // 2  
                hashMap[diff] -= (pairs * 2)
                res += pairs 
        print(res)
        return res
    
def main():
    self = Solution
    # nums = [3, 1, 3, 4, 3]
    # k = 6
    # nums = [1, 2, 3, 4]
    # k = 5
    nums = [2, 2, 2, 3, 1, 1, 4, 1]
    k = 4
    # nums = [3, 5, 1, 5]
    # k = 2
    # nums = [4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4]
    # k = 3

    Solution.maxOperations(self, nums, k)
main()