class Solution:
    def longestWord(self, words) -> str:
        sortedWords = sorted(words, key=len)
        print("sortedWords: ", sortedWords, end="\n\n")
        candidates = []
        ok = True

        for i in range(len(sortedWords)-1, -1,-1):
            word = sortedWords[i]
            j = len(word)-1
            remaining = sortedWords[: i] + sortedWords[i+1: ]
            remainingSet = set(remaining)

            while j>0:
                print(word[: j])
                if word[: j] in remainingSet:
                    ok = True
                    j -= 1
                else:
                    ok = False
                    break
            if ok: candidates.append(word)
        print(candidates)

        hashMap = {}
        for candidate in candidates:
            if len(candidate) in hashMap:
                hashMap[len(candidate)].append(candidate)
            else:
                hashMap[len(candidate)] = [candidate]
        print(hashMap)

        firstValue = next(iter(hashMap.values()))
        firstValue = sorted(firstValue)
        print(firstValue)
        print(firstValue[0])
        return firstValue[0]

def main():
    self = Solution
    # words = ["w","wo","wor","worl","world"]
    # words = ["a","banana","app","appl","ap","apply","apple"]
    words = ["b","br","bre","brea","break","breakf","breakfa","breakfas","breakfast","l","lu","lun","lunc","lunch","d","di","din","dinn","dinne","dinner"]
    words = ["ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"]
    Solution.longestWord(self, words)
main()