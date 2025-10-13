class UnionFind:
    def __init__(self):
        self.parents = dict()
        self.sizes = dict()
        self.headcount = 0

    def __contains__(self, key):
        return key in self.parents
    
    def insert(self, row, col):
        if self.__contains__((row, col)): return

        self.parents[(row, col)] = (row, col)
        self.sizes[(row, col)] = 1
        self.headcount += 1

    def find(self, i):
        while i != self.parents[i]:
            self.parents[i] = self.find(self.parents[i])
            i = self.parents[i]
        return i
    
    def union(self, p, q):
        root_p, root_q = map(self.find, (p, q))
        if root_p == root_q: return
        small, big = sorted([root_p, root_q], key=lambda x: self.sizes[x])
        self.parents[small] = big
        self.sizes[big] += self.sizes[small]
        self.headcount -= 1

class Solution:
    def numIslands2(self, m, n, positions):
        uf = UnionFind()
        num_islands = []

        for row, col in positions:
            uf.insert(row, col)
            for rr, cc in [(row+1, col), (row-1, col), (row, col-1), (row, col+1)]:
                if (rr, cc) not in uf: continue
                uf.union((row, col), (rr, cc))
            num_islands.append(uf.headcount)
        
        return num_islands
    

def main():
    solution = Solution()
    m = 3
    n = 3
    positions = [[0,0],[0,1],[1,2],[2,1]] # [1, 1, 2, 3]
    m = 1
    n = 1
    positions = [[0,0]] # [1]
    m = 2
    n = 2
    positions = [[0,0],[1,1],[0,1]] # [1, 2, 1] 
    solution.numIslands2(m, n, positions)
main()