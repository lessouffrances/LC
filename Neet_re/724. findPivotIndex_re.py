class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        nums = [0] + nums + [0]
        for i in range(1, len(nums) - 1):
            left_sum = sum(nums[:i])
            # print(left_sum)
            right_sum = sum(nums[i + 1:])
            # print(right_sum)
            if left_sum == right_sum:
                return i - 1
        return -1

def main():
    self = Solution()
    # nums = [1,7,3,6,5,6]
    # nums = [1, 2, 3]
    nums = [2, 1, -1]
    # output = 3
    print(Solution.pivotIndex(self, nums))
main()