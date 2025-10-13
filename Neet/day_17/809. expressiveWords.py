class Solution:
    def expressiveWords(self, s: str, words) -> int:
        decomposedS = Solution.decompose(self, s)
        print(decomposedS)
        count = 0
        ok = False

        for word in words:
            decomposedWord = Solution.decompose(self, word)
            print(decomposedWord)
            if len(decomposedWord) != len(decomposedS):
                break

            for i, group in enumerate(decomposedWord):
                if group == decomposedS[i]:
                    ok = True
                    print(ok)
                    continue
                if group in decomposedS[i] and len(group) <= len(decomposedS[i]) and len(decomposedS[i]) >= 3:
                    ok = True
                    print(ok)
                    continue
                else:
                    ok = False
                    print(ok)
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
        # print(res)
        return res

def main():
    self = Solution
    s = "heeellooo"
    words = ["hello", "hi", "helo"] # output = 1
    s = "zzzzzyyyyy"
    words = ["zzyy","zy","zyy"] # output = 3
    s = "heeelllooo"
    words = ["hellllo"]
    # Solution.decompose(self, s)
    Solution.expressiveWords(self, s, words)
main()