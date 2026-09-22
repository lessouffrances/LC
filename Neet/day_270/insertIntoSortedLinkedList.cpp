/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution 
{
    public:
    Node* insert(Node* head, int insertVal) 
    {
        // find the location where the prev->val < insertVal and curr->val > insertVal
        if (!head) {
            Node* insertNode = new Node(insertVal);
            insertNode->next = insertNode;
            return insertNode;
        }

        Node* prev = head;
        Node* curr = head->next;
        Node* insertNode = new Node(insertVal);

        while (curr != head) {
            if (prev->val <= insertVal && curr->val >= insertVal) {
                break;
            }
            if (prev->val > curr->val) {
                if (prev->val <= insertVal || curr->val >= insertVal) {
                    break;
                }
            } 
            prev = curr;
            curr = curr->next;
        }

        prev->next = insertNode;
        insertNode->next = curr;
        return head;
    }
};