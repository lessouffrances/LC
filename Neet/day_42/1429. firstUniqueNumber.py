from collections import Counter

class FirstUnique:
    def __init__(self, nums):
        self.unique = []
        self.seen = set()
        self.stack = []
        for num in nums:
            self.add(num)
        
    def showFirstUnique(self) -> int:
        return self.unique[0] if self.unique else -1

    def add(self, value: int) -> None:
        self.stack.append(value)

        if value not in self.seen:
            self.unique.append(value)
            self.seen.add(value)
        else:
            if value in self.unique:
                self.unique.remove(value)
        
# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)