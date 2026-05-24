class Solution(object):
    def rotateString(self, s, goal):
        if len(s) != len(goal):
            return False
        
        double_s = s[:] + s[:]
        if goal in double_s: return True
        return False

        