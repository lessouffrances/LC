import sys
# import numpy as np
# import pandas as pd
# from sklearn import ...

class Employee:
    def __init__(self, name):
        self.name = name
        self.subordinates = []

class Organization:
    def __init__(self):
        self.employees = {} # name : employee
    
    def addRelationship(self, subordinateName, managerName):
        if managerName not in self.employees:
            self.employees[managerName] = Employee(managerName) # add the manager into the hierarchy if no exists
        if subordinateName not in self.employees:
            self.employees[subordinateName] = Employee(subordinateName) # add the subordinate into hierarchy if no exists
         
        manager = self.employees[managerName]
        subordinate = self.employees[subordinateName]
        manager.subordinates.append(subordinate)

    def findRoot(self):
        potentialRoots = set(self.employees.keys()) # set of employees' names
        for employee in self.employees.values():
            for subordinate in employee.subordinates:
                if subordinate.name in potentialRoots:
                    potentialRoots.remove(subordinate.name)
        
        return self.employees[potentialRoots.pop()]
    
    def findDepth(self, root, employeeName, depth):
        if root is None:
            return -1
        if root.name == employeeName:
            return depth
        for subordinate in root.subordinates:
            d = self.findDepth(subordinate, employeeName, depth+1)
            if d != -1:
                return d
        return -1

    def findLca(self, root, employee1, employee2): #lowest common ancestor -> LCA
        if root is None:
            return None
        if root.name == employee1 or root.name == employee2:
            return root

        numFound = 0
        found = None
        
        for subordinate in root.subordinates:
            lca = self.findLca(subordinate, employee1, employee2)
            if lca:
                numFound += 1
                found = lca
        
        if numFound == 2:
            return root

        return found
    
    def distanceBetweenEmployees(self, employee1, employee2):
        if employee1 not in self.employees or employee2 not in self.employees:
            return -1
        
        root = self.findRoot()
        lca = self.findLca(root, employee1, employee2)
        depth1 = self.findDepth(lca, employee1, 0)
        depth2 = self.findDepth(lca, employee2, 0)
        
        return depth1 + depth2

    def areAtSameLevel(self, employee1, employee2):
        root = self.findRoot()
        depth1 = self.findDepth(root, employee1, 0)
        depth2 = self.findDepth(root, employee2, 0)
        
        return depth1 == depth2 
        
def main():
    import sys
    inputFile = 'sample-input-3.txt'
    with open(inputFile, 'r') as file:
        pairs = file.read().strip().split('\n')
        print(pairs)
    
    if len(pairs) <= 1:
        return 
    
    employee1, employee2 = pairs[0].split('/')
    organization = Organization()
    for pair in pairs[1:]:
        subordinate, manager = pair.split('/')
        print(subordinate, manager)
        organization.addRelationship(subordinate, manager)
        
    levels = organization.distanceBetweenEmployees(employee1, employee2)
    sameLevel = organization.areAtSameLevel(employee1, employee2)

    if sameLevel == True:
        levels = 0

    if levels != -1:
        print(levels)
        return levels
    else: 
        return 

if __name__ == "__main__":
    main()
