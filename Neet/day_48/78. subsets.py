class Solution:
    def subsets(self, nums):
        if len(nums) == 1:
            return [[], [nums[0]]]

        prev_seto_list = []
        for i in range(len(nums)):
            if i == 0:
                prev_seto_list = [[], [nums[0]]]
            else:
                next_seto_list = []
                for seto in prev_seto_list:
                    new_seto = seto + [nums[i]]
                    next_seto_list.append(new_seto)
                    next_seto_list.append(seto)

                prev_seto_list = next_seto_list
        print(next_seto_list)
        return next_seto_list

def main():
    solution = Solution()
    # nums = [1,2,3,4]
    # [[],[1],
    # [2],[1,2],
    # [3],[1,3],[2,3],[1,2,3]
    # [4],[1,4],[2,4],[1,2,4],[3,4],[1,3,4],[2,3,4],[1,2,3,4]]
    nums = [0]
    # [[],[0]]
    solution.subsets(nums)
main()