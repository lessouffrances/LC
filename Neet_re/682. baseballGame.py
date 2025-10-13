class Solution:
    def calPoints(self, ops) -> int:
        stack = []
        for op in ops:
            if op == "C":
                stack.pop()
            elif op == "D":
                a = stack[-1]
                stack.append(2*a)
            elif op == "+":
                a, b = stack[-1], stack[-2]
                stack.append(a+b)
            else:
                stack.append(int(op))

        return sum(stack)

def main():
    self = Solution
    ops = ["5","-2","4","C","D","9","+","+"] 
    
    print(Solution.calPoints(self, ops))

main()


