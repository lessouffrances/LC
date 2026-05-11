/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// T: O(N)
// S: O(N)

class Solution 
{
    public:
    Node* copyRandomList(Node* head) 
    {
        if (!head) return head;

        unordered_map<Node*, Node*> oldToNew;
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            oldToNew[curr] = newNode;
            curr = curr->next;
        }

        // assign pointers
        curr = head;
        while (curr) {
            Node* newNode = oldToNew[curr];
            newNode->next = oldToNew[curr->next];
            newNode->random = oldToNew[curr->random];
            curr = curr->next;
        }

        return oldToNew[head];
    }
};