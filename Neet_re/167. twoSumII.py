class Solution:
    def twoSum(self, numbers, target):
        hashMap = {}
        res = []

        for i in range(len(numbers)):
            hashMap[numbers[i]] = i+1
        
        for i in range(len(numbers)):
            diff = target - numbers[i]
            if diff in hashMap and hashMap[diff] != i:
                res.append(i+1)
                res.append(hashMap[diff])
                res.sort()
                return res
            else:
                continue
        
def main():
    self = Solution()
    numbers = [2,7,11,15]
    target = 9
    print(Solution.twoSum(self, numbers, target))

main()