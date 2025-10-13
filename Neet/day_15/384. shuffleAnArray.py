class Solution:

    def __init__(self, nums):
        self.originalNums = nums.copy()
        self.nums = nums
        return None

    def reset(self):
        return self.originalNums

    def shuffle(self):
        return self.nums[-1:] + self.nums[:-1]

def main():
    instructions = ["Solution","shuffle","reset","shuffle"]
    nums = [7, 6, 5, 4, 3, 2, 1]
    res = []
    obj = Solution(nums)
    res.append(obj)
    param_1 = obj.reset()
    res.append(param_1)
    param_2 = obj.shuffle()
    res.append(param_2)
    print(res)

main()
        
# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()