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

class Solution 
{
    public:
    Node* copyRandomList(Node* head) 
    {
        if (!head) return nullptr;

        // build oldToNew map
        unordered_map<Node*, Node*> oldToNew;
        Node* curr = head;

        while (curr) {
            Node* node = new Node(curr->val);
            oldToNew[curr] = node;
            curr = curr->next;
        }

        // assign pointers
        curr = head;

        while (curr) {
            Node* newNode = oldToNew[curr];
            newNode->random = oldToNew[curr->random];
            newNode->next = oldToNew[curr->next];
            curr = curr->next;
        }

        return oldToNew[head];
    }
};