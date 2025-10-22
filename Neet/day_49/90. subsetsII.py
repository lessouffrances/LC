class Solution:
    def subsetsWithDup(self, nums):
        nums.sort()
        if len(nums) == 1:
            return [[], [nums[0]]]

        for i in range(len(nums)):
            if i == 0:
                curr_set = [[], [nums[0]]]

            else:
                curr_set_copy = curr_set.copy()
                for seto in curr_set_copy:
                    next_seto = seto+[nums[i]]
                    print(f"the next seto is {next_seto}", end='\n')
                    if next_seto not in curr_set:
                        curr_set.append(next_seto)

        print(curr_set)
        return curr_set
                    
            
def main():
    solution = Solution()
    nums = [1,2,2]
    # [[],[1],[1,2],[1,2,2],[2],[2,2]]
    nums = [0]
    # #[[],[0]]
    nums = [4,4,4,1,4]
    # [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]

    solution.subsetsWithDup(nums)
main()