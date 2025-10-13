class Solution:
    def expressiveWords(self, s, words) -> int:
        sDecomposition = Solution.decompose(self, s)
        count = 0

        for word in words:
            ok = True
            wordDecomposition = Solution.decompose(self, word)
            if len(sDecomposition) != len(wordDecomposition):
                continue
            for sGroup, wordGroup in zip(sDecomposition, wordDecomposition):
                print((sGroup, wordGroup))
                if sGroup == wordGroup:
                     continue
                if not ((wordGroup in sGroup) and (len(sGroup) >= 3)):
                    ok = False
                    break
            if ok: count += 1
        print(count)
        return count

    def decompose(self, string):
        l = 0
        res = []
        currGroup = ""

        for r in range(len(string)):
            if string[r] == string[l]:
                currGroup += string[r]
            else:
                res.append(currGroup)
                currGroup = ""
                l = r
                currGroup += string[r]    
        res.append(currGroup)           
        # print(res)
        return res


def main():
    self = Solution
    s = "heeellooo"
    words = ["hello", "hi", "helo"] # output = 1

    # s = "zzzzzyyyyy"
    # words = ["zzyy","zy","zyy"] # output = 3

    Solution.expressiveWords(self, s, words)

    # Solution.decompose(self, "heeellooo")

main()