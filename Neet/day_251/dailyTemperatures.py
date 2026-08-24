class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        if len(temperatures) == 0: return []
        stack = [] # [temp, idx]
        answer = [0] * len(temperatures)
        
        for i in range(len(temperatures)):
            while stack and stack[-1][0] < temperatures[i]:
                daysWait = i-stack[-1][1]
                index = stack[-1][1]
                answer[index] = daysWait
                stack.pop()
            stack.append( [temperatures[i], i] )
        return answer
