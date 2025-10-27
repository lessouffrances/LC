class Solution:
    def findLUSlength(self, strs) -> int:
        def isSubsequence(s, t):
            #if the length of the string is greater than the length of the target
            if len(s) > len(t):
                return False
            
            # initialize index
            i = 0
            # look at each char in target
            for char in t:
                # if there is a sequential match 
                if i < len(s) and s[i] == char:
                    i += 1
            return i == len(s)
        
        # start by looking at the longest str
        strs.sort(key=len, reverse=True)

        # iterate thru each word
        for i, word in enumerate(strs):
            found = True
            # look at other word
            for j in range(len(strs)):
                if j != i:
                    # If this word is a subsequence of that word, break
                    if isSubsequence(word, strs[j]):
                        found = False
                        break
                # if this flag was not flipped
                if found:
                    # this is the longest uncommon subsequence
                    return len(word)
        
        return -1






def main():
    solution = Solution()
    strs = ["aba","cdc","eae"] #3
    strs = ["aaa","aaa","aa"] #-1
    solution.findLUSlength(strs)
main()