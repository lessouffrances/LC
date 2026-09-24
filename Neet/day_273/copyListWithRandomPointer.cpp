
class Solution 
{
    public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> oldToNew;

        Node* curr = head;
        while (curr) {
            Node * newNode = new Node(curr->val);
            oldToNew[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            curr = curr->next;
        }
        return oldToNew[head];
    }
};