class Solution:
    def countAndSay(self, n: int) -> str:  
        if n == 1:
            return "1"

        def countAndSayHelper(digits):
            left, right = 0, 0
            curr_count = 0
            res = ""
            
            while right < len(digits):
                while right < len(digits) and digits[right] == digits[left]:
                    curr_count += 1 
                    right += 1
            

                res += str(curr_count)+digits[left]
                left = right
                curr_count = 0
            
            return res

        # countAndSayHelper("1")
        # countAndSayHelper("11")
        # countAndSayHelper("21")
        # countAndSayHelper("1211")
        
        for i in range(n):
            if i == 0:
                prev_term = "1"
            else:
                prev_term = countAndSayHelper(prev_term)

        print(f"{prev_term}")
        return prev_term
            

        
def main():
    solution = Solution()
    n = 4 #1211 
    # n = 3 #21
    # n = 2 #11
    # n = 1 #1
    solution.countAndSay(n) 
main()