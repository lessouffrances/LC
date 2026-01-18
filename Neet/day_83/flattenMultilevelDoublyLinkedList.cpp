class Node 
{
    public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution 
{
    public:
    Node* flatten(Node* head) 
    {
        if (!head) return nullptr;

        Node* curr = head;
        stack<Node*> deck;

        while (curr) {
            if (curr->child) {
                if (curr->next) {
                    deck.push(curr->next);
                }
                curr->next = curr->child;
                curr->child->prev = curr;
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