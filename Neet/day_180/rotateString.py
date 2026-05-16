class Solution(object):
    def rotateString(self, s, goal):
        if len(s) != len(goal):
            return False
        
        double_s = s + s
        if goal not in double_s:
            return False
        return True
        