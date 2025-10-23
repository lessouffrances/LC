class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
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
                    if next_seto not in curr_set:
                        curr_set.append(next_seto)
        return curr_set

    

        