class Solution:
    def longestCommonPrefix(self, strs) -> str:
        res = ""

        for i in range(len(strs[0])): 
            for s in strs: 
                if i == len(s) or s[i] != strs[0][i]:
                    return res
            res += strs[0][i]
        
        return res
# this iteration uses the strs[0] as a comparison benchmark and 
# check for each other str in the strs list. 
 

def main():
    self = Solution()
    strs = ["flower","flow","flight"]
    print(Solution.longestCommonPrefix(self, strs))
main()