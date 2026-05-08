// struct Node
// {
//     int val;
//     Node* prev;
//     Node* child;
//     Node* next;

//     Node(int x): val(x), prev(nullptr), child(nullptr), next(nullptr) {}
// };

// T: O(N)
// S: O(N)
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
                    // save the next on stack
                    deck.push(curr->next);
                }

                // reconnect
                curr->next = curr->child;
                curr->child = nullptr;
                curr->next->prev = curr;
            }

            if (!curr->next && !deck.empty()) {
                Node* saved = deck.top();
                deck.pop();
                curr->next = saved;
                saved->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};