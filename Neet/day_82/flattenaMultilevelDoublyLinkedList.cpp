/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution 
{
    public:
    Node* flatten(Node* head) 
    {
        if (!head) return nullptr;

        Node* curr = head;
        stack<Node*> deck;

        while (curr) {
            // if this node has child, connect to the child linked list 
            // and push the next to the stack for reconnect 
            if (curr->child) {
                if (curr->next) {
                    deck.push(curr->next);
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }

            // following the linked list and reconnected childs, 
            // if there is savedNodes on the stack, reconnect with them 
            if (!curr->next && !deck.empty()) {
                Node* savedNext = deck.top();
                deck.pop();
                curr->next = savedNext;
                savedNext->prev = curr;
            }

            curr =  curr->next;
        }
        return head;
    }
};