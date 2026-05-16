class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        self.ancestor_stack = set()
        self.visited = set()
        self.finish_order = []
        self.graph = {}
        self.buildGraph(numCourses, prerequisites)
        
        for course in range(numCourses):
            if course in self.visited:
                continue
            if self.dfsHasCycle(course):
                return []
        return self.finish_order[::-1]

    def buildGraph(self, numCourses, prerequisites):
        for course in range(numCourses):
            self.graph[course] = []
        
        for prep in prerequisites:
            u = prep[1]
            v = prep[0]
            self.graph[u].append(v)
    
    def dfsHasCycle(self, u):
        self.ancestor_stack.add(u)
        self.visited.add(u)

        for v in self.graph[u]:
            if v in self.ancestor_stack:
                return True
            if v in self.visited:
                continue
            if self.dfsHasCycle(v):
                return True
        self.ancestor_stack.remove(u)
        self.finish_order.append(u)
        return False



        