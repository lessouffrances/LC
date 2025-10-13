class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        prevMap = {}
        for i, num in enumerate(numbers):
            diff = target - num
            
            if diff in prevMap:
                return [prevMap[diff] + 1, i + 1]
            prevMap[num] = i
            

def main():
    self = Solution()
    numbers = [2, 7, 11, 15]
    target = 9
    print(Solution.twoSum(self, numbers, target))
main()