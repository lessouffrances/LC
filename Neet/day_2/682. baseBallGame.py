class Solution:
    def calPoints(self, operations: list[str]) -> int:
        stack = []
        
        for op in operations:
            if op == "+":
                stack.append(stack[-1] + stack[-2])

            elif op == "D":
                stack.append(2 * stack[-1])

            elif op == "C":
                stack.pop()

            else: # "int x"
                stack.append(int(op))

        return sum(stack)
    
    def main():
        self = Solution()
        operations = ["5", "-2", "4", "C", "D", "9", "+", "+"]
        Solution.calPoints(self, operations)
    
    main()

    

