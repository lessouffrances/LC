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

// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    Node* copyRandomList(Node* head) 
    {
        if (!head) return head;

        // build oldToNews containing only nodes
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            oldToNew[curr] = newNode;
            curr = curr->next;
        }

        // get the same pointers as old ones
        curr = head;
        while (curr) {
            Node* newNode = oldToNew[curr];
            newNode->next = oldToNew[curr->next];
            newNode->random = oldToNew[curr->random];
            curr = curr->next;
        }

        // return the new head
        return oldToNew[head];
    }

    private:
    unordered_map<Node*, Node*> oldToNew;
}