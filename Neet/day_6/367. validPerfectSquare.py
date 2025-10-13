class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        for i in range(1, num + 1): # num + 1: 1 * 1 = 1
            if i * i == num:
                return True
            if i * i > num:
                return False
 
def main():
    self = Solution
    num = 16
    
    
    print(Solution.isPerfectSquare(self, num))
main()