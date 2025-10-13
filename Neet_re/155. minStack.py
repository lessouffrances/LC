class MinStack:

    def __init__(self):
        self.stack = []
    
    def push(self, val: int) -> None:
        self.stack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        currMin, mini = self.stack[0], self.stack[0]

        for i in range(len(self.stack)):
            currMin = self.stack[i]
            mini = min(currMin, mini)
        return mini
        
        

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

def main():
    obj = MinStack()
    obj.push(-2)
    obj.push(0)
    obj.push(-3)
    print(obj.stack)
    print(obj.getMin())
    print(obj.stack)
    obj.pop()
    obj.top()
    obj.getMin()
main()