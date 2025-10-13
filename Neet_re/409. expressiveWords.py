from collections import Counter
class Solution:
    def expressiveWords(self, s: str, words) -> int:
        count = 0
        sList = Solution.decompose(self, s)
        print("sList: ", sList, end="\n\n")

        for word in words:
            ok = True
            wordList = Solution.decompose(self, word)
            print(wordList)
            if len(wordList) != len(sList):
                continue
            for i, group in enumerate(sList):
                if group == wordList[i]:
                    continue
                if wordList[i] in group and len(group) >= 3:
                    continue
                else:
                    ok = False
                    break
            if ok: count += 1
        print(count)
        return count

    def decompose(self, word):
        l = 0
        res = []
        currGroup = ""
        for r in range(len(word)):
            if word[r] == word[l]:
                currGroup += word[r]
            else:
                res.append(currGroup)
                l = r
                currGroup = word[l]
        res.append(currGroup)
        return res

def main():
    self = Solution
    s = "heeellooo"
    words = ["hello", "hi", "helo"] # output = 1
    s = "zzzzzyyyyy"
    words = ["zzyy","zy","zyy"] # output = 3
    Solution.expressiveWords(self, s, words)
main()