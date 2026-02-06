


class Solution 
{
    public:
    Node* flatten(Node* head) 
    {
        if (!head) return nullptr;

        stack<Node*> deck;
        Node* curr = head;

        while (curr) {
            if (curr->child) {
                if (curr->next) {
                    // save next to stack
                    deck.push(curr->next);
                }
                // reconnect next to child
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
            }

            if (!curr->next && !deck.empty()) {
                Node* savedNode = deck.top();
                deck.pop();
                curr->next = savedNode;
                savedNode->prev = curr;
            }
            
            curr = curr->next;
        }

        return head;
    }
};