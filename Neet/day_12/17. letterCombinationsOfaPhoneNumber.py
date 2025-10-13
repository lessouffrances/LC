class Solution:
    def letterCombinations(self, digits):
        res = []
        digitToChar = {"2": "abc", 
                       "3": "def",
                       "4": "ghi",
                       "5": "jkl",
                       "6": "mno",
                       "7": "pqrs",
                       "8": "tuv",
                       "9": "wxyz"}
        
        def backTrack(i, currString):
            # base case
            if len(currString) == len(digits):
                res.append(currString)
                return 
            
            # recursive case
            for char in digitToChar[digits[i]]:
                backTrack(i+1, currString+char)

        # kick off the recursion if digits
        if digits:
            backTrack(0, "")
        
        return res

def main():
    self = Solution()
    digits = "23"
    # Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    # digits = ""
    # Output: ["a","b","c"]
    # digits = "2"
    # Output: ["a","b","c"]

    print(Solution.letterCombinations(self, digits))

main()