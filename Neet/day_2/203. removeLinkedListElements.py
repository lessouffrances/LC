# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: [ListNode], val: int) -> [ListNode]:
        dummy = ListNode(next=head)
        prev = dummy
        curr = head
        
        while curr:
            next = curr.next
            if curr.val == val:
                prev.next = next # update the pointer to get rid of the curr 
            else:
                prev = curr
            
            curr = next
        
        return dummy.next


def main():
    head = [7, 7, 7, 7]
    val = 7
    self = Solution()
    print(Solution.removeElements(self, head, val))


main()

