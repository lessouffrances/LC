class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def __init__(self):
        self.head = None

    def insert(self, data):
        newNode = ListNode(data)

        if not self.head:
            self.head = newNode
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = newNode

    def delete(self, value):
        if not self.head:
            return 
        
        if self.head.val == value:
            self.head = self.head.next
            return 
        
        current = self.head
        while current.next and current.next.val != value:
            current = current.next
        
        if current.next:
            current.next = current.next.next
        else: 
            print("Value not found!")
        
