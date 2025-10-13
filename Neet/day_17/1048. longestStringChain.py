class Solution:
    def longestStrChain(self, words) -> int:
        words.sort(key=len)
        print(words)
        if len(words) == 1:
            return 1
        
        count = 1
        l, r = 0, 1
        while r < len(words):
            if Solution.isPredecessorOf(self, words[l], words[r]):
                count += 1
                l, r = l+1, r+1
            else:
                if (r+1) < len(words) and len(words[r+1]) == len(words[r]):
                    r = r+1
                else:
                    l, r = l+1, r+1

        return count

    def isPredecessorOf(self, a, b):
        i = 0
        for char in b:
            if i < len(a) and a[i] == char:
                i += 1
        return i == len(a) and len(b) == len(a)+1

        



def main():
    self = Solution
    # words = ["a","b","ba","bca","bda","bdca"] 
    # words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    # words = ["abcd","dbqca"]

    # words = ["bdca","bda","ca","dca","a"] # output = 4
    # words = ["a","b","ba","bca","bda","bdca"] # output = 4
    words = ["bdca","bda","ca","dca","a"] # output = 4

    print(Solution.longestStrChain(self, words))
    # print(Solution.isPredecessorOf(self, "xbc", "cxbc"))
main()