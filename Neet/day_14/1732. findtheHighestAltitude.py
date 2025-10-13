class Solution:
    def largestAltitude(self, gain) -> int:
        # altitudes = [0] * len(gain)
        gain = [0] + gain

        for i in range(1, len(gain)):
            gain[i] = gain[i-1]+ gain[i]

        return max(gain)










def main():
    self = Solution
    gain = [-5,1,5,0,-7] # 1
    
    # gain = [-4,-3,-2,-1,4,3,2] # 0

    print(Solution.largestAltitude(self, gain))
main()