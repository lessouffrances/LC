class Solution:
    def wordBreak(self, s, wordDict) -> bool:
        wordSet = set(wordDict)
        dp = [False] * (len(s) + 1)
        dp[0] = True
        
        for i in range(1, len(s) + 1):
            for j in range(i):
                print(f"The dp[j] is {dp[j]}")
                print(f"s[j:i] is {s[j:i]}, and it {s[j:i] in wordSet} in wordSet.", end="\n\n")
                if dp[j] and s[j:i] in wordSet:
                    dp[i] = True
                    break
        return dp[-1]


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