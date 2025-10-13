class Solution:
    def isPalindrome(self, x: int) -> bool:
        thisOrder, thatOrder  = "", ""
        x = str(x)

        for i in range(len(x)):
            thisOrder += x[i]
            print(thisOrder)
        
        for j in range(len(x)-1, -1, -1):
            thatOrder += x[j]
            print(thatOrder)
        
        return thisOrder == thatOrder 
        


def main():
    self = Solution
    x = 121
    print(Solution.isPalindrome(self, x))
main()