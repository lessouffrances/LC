class Solution:
    def maxSubstringWithCost(self, s, t, K) -> int:
        if not s or not t:
            return 0
        
        left, right = 0, 0
        res, currLength = 0, 0
        initialBudget = K

        for right in range(len(s)):
            cost = abs(ord(s[right])-ord(t[right]))
            print("The current cost to swap is: ", cost)

            if cost <= K:
                K -= cost
                currLength = (right-left+1)
                res = max(currLength, res)
                print("The current length is: ", currLength)

            else:
                K = initialBudget
                left = right+1
                currLength = 0

        return res

def main():
    solution = Solution()
    s = 'adpgki'
    t = 'cdmxki'
    K = 6 #3

    # s = 'hffk'
    # t = 'larb'
    # K = 3 #0

    # s = 'uaccd'
    # t = 'gbbeg'
    # K = 4 #3

    print(solution.maxSubstringWithCost(s, t, K))
main()