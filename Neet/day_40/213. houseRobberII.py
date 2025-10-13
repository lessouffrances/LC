class Solution:
    def rob(self, nums) -> int:
        if len(nums) == 1:
            return nums[0]

        dp_1 = [ [0, set()] for _ in range(len(nums)) ]
        dp_2 = [ [0, set()] for _ in range(len(nums)) ]
        print(dp_1)
        print(dp_2)

        for i in range(1, len(nums)):
            dp_1[i][0] = max( dp_1[i-1][0], nums[i-1]+dp_1[i-2][0] )
            if dp_1[i-1][0] > nums[i-1]+dp_1[i-2][0]:
                dp_1[i][1] = dp_1[i-1][1]
                dp_1[i][1] = dp_1[i-2][1] | {i-1}
        print(f" ***** normal dp_1 ********: {dp_1}", end="\n")

        for i in range(1, len(nums)):
            dp_2[i][0] = max( dp_2[i-1][0], nums[i]+dp_2[i-2][0] )
            if dp_2[i-1][0] > nums[i]+dp_2[i-2][0]:
                dp_2[i][1] = dp_2[i-1][1]
                dp_2[i][1] = dp_2[i-2][1] | {i-1}
        print(f" ***** normal dp_2 ********: {dp_2}", end="\n")

        print(max(dp_1[-1][0], dp_2[-1][0]))
        return max(dp_1[-1][0], dp_2[-1][0])


def main():

    solution = Solution()
    # nums = [2,2,4,3,2,5] #10
    # nums = [1,1,3,6,7,10,7,1,8,5,9,1,4,4,3] #41
    # nums = [2,3,2] #3
    # nums = [1, 2, 3, 1] #4
    # nums = [1, 2, 3] #3
    # nums = [2,1,1,2] #3
    solution.rob(nums)
main()
