class Solution:
    def wordBreak(self, s, wordDict) -> bool:
        


def main():
    solution = Solution()
    # s = "leetcode"
    # wordDict = ["leet","code"] #true
    # s = "applepenapple"
    # wordDict = ["apple","pen"] #true
    # s = "catsandog"
    # wordDict = ["cats","dog","sand","and","cat"] #false
    # s = "cars"
    # wordDict = ["car","ca","rs"] #true
    s = "abcd"
    wordDict = ["a","abc","b","cd"] #true
    print(solution.wordBreak(s, wordDict))
main()