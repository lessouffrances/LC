class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        n = len(nums)
        lst = []
        hashSet = set(nums)
        for i in range(1, n + 1):
            if i not in hashSet:
                lst.append(i)

        print(lst)
        return lst
        
def main():
    self = Solution()
    # nums = [4,3,2,7,8,2,3,1]
    nums = [1,1]

    Solution.findDisappearedNumbers(self, nums)
main()