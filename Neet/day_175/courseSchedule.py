class Solution(object):
    def canFinish(self, num_courses, prerequisites):
        if len(prerequisites) == 0:
            return True

        self.graph = {}
        self.visited = set()
        self.ancestor_stack= set()
        self.buildGraph(num_courses, prerequisites)

        for course in range(num_courses):
            if course in self.visited:
                continue
            if self.dfsHasCycle(course):
                return False
        return True


    def dfsHasCycle(self, u):
        self.visited.add(u)
        self.ancestor_stack.add(u)

        for v in self.graph[u]:
            if v in self.ancestor_stack:
                return True
            if v in self.visited:
                continue
            if self.dfsHasCycle(v):
                return True
        
        self.ancestor_stack.remove(u)
        return False

    def buildGraph(self, num_courses, prerequisites):
        for course in range(num_courses):
            self.graph[course] = []

        for v, u in prerequisites:
            self.graph[u].append(v)


