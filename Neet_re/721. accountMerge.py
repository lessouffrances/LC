from collections import defaultdict
class UnionFind:
    def __init__(self, n):
        self.par = [ i for i in range(n) ]
        self.rank = [1] * n

    def find(self, x):
        while x!= self.par[x]:
            self.par[x] = self.par[self.par[x]]
            x = self.par[x]
        return x

    def union(self, x1, x2):
        p1, p2 = self.find(x1), self.find(x2)
        if p1 == p2:
            return False
        if self.rank[p1]>self.rank[p2]:
            self.par[p2] = p1
            self.rank[p1] += self.rank[p2]
        else:
            self.par[p1] = p2
            self.rank[p2] += self.rank[p1]
        return True

class Solution:
    def accountsMerge(self, accounts):
        uf = UnionFind(len(accounts))
        emailToAcc = {} # email -> index of acc

        for i, a in enumerate(accounts):
            for e in a[1: ]:
                if e in emailToAcc:
                    uf.union(i, emailToAcc[e])
                else:
                    emailToAcc[e] = i
            

        emailGroup = defaultdict(list) # index of acc -> list of emails
        for e, i in emailToAcc.items():
            leader = uf.find(i)
            emailGroup[leader].append(e)
        
        res = []
        for i, emails in emailGroup.items():
            name = accounts[i][0]
            res.append([name]+sorted(emailGroup[i])) # array concat
        
        return res

def main():
    self = Solution
    accounts = [["David","David0@m.co","David1@m.co"],
                ["David","David3@m.co","David4@m.co"],
                ["David","David4@m.co","David5@m.co"],
                ["David","David2@m.co","David3@m.co"],
                ["David","David1@m.co","David2@m.co"]]
    Solution.accountsMerge(self, accounts)
main()