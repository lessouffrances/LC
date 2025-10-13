class Solution:
    def longestCommonPrefix(self, strs) -> str:
        res = ""

        for i in range(len(strs[0])):
            for s in strs:
                if i == len(s) or s[i] != strs[0][i]:
                    return res
            res += strs[0][i]

        print(res)
        return res
                

def main():
    self = Solution
    strs = ["flower","flow","flight"]
    # strs = ["dog","racecar","car"]
    Solution.longestCommonPrefix(self, strs)

main()