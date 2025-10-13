class Solution:
    def camelMatch(self, queries, pattern):
        ok = False
        res = []
        if pattern.islower():
            for query in queries:
                if Solution.isSubsequence(self, pattern, query):
                    res.append(True)
                else:
                    res.append(False)
            return res
                    
        decomposedP = Solution.decompose(self, pattern)
        print("pattern: ", decomposedP)

        for query in queries:
            decomposedQ = Solution.decompose(self, query)
            if len(decomposedQ) != len(decomposedP):
                res.append(False)
                continue
            for i, string in enumerate(decomposedQ):
                if Solution.isSubsequence(self, decomposedP[i], string):
                    ok = True
                    continue
                else:
                    ok = False
                    break
            if ok: res.append(True)
            else: res.append(False)
        return res

    def decompose(self, string):
        for i, char in enumerate(string):
            if char.isupper():
                l = i
                break

        res = []
        curr = ""
        for r in range(l, len(string)):
            if string[r].isupper() and curr != "":
                res.append(curr)
                curr = ""
                l = r
                curr += string[l]
            else:
                curr += string[r]

        res.append(curr)
        return res
    
    def isSubsequence(self, string, target):
        i = 0
        for char in target:
            if i < len(string) and char == string[i]: i += 1
        return i == len(string)

def main():
    self = Solution
    queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
    pattern = "FoBa"
    queries = ["CompetitiveProgramming","CounterPick","ControlPanel"]
    pattern = "CooP"

    queries = ["uAxaqlzahfialcezsLfj","cAqlzyahaslccezssLfj","AqlezahjarflcezshLfj","AqlzofahaplcejuzsLfj","tAqlzahavslcezsLwzfj","AqlzahalcerrzsLpfonj","AqlzahalceaczdsosLfj","eAqlzbxahalcezelsLfj"]
    pattern = "AqlzahalcezsLfj"

    queries = ["mifeqvzphnrv","mieqxvrvhnrv","mhieqovhnryv","mieqekvhnrpv","miueqrvfhnrv","mieqpvhzntrv","gmimeqvphnrv","mieqvhqyunrv"]
    pattern = "mieqvhnrv"
    # print(Solution.decompose(self, "uAxaqlzahfialcezsLfj"))
    # print(Solution.isSubsequence(self, "Coo", "Control"))
    print(Solution.camelMatch(self, queries, pattern))
main()