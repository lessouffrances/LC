class Solution:
    def reverseString(self, string):
        if len(string) == 1:
            return string
        return Solution.reverseString(self, string[1:]) + string[0]

def main():
    self = Solution
    string = "abcdefg"
    print(Solution.reverseString(self, string))
main()
    



