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
    Node* sortMultilevelList(Node* head) 
    {
        if (!head) return nullptr;

        // collect all the values in the multilevel linkedlist
        collectValues(head);

        // sort the array
        sort(vals.begin(), vals.end());

        // populate the values in the same structure
        int startIdx = 0;
        redistributeValues(head, startIdx);

        return head;
    }
    private:
    vector<int> vals;
    void collectValues(Node* node)
    {
        if (!node) return;
        vals.push_back(node->val);

        if (node->child) {
            collectValues(node->child);
        }

        if (node->next) {
            collectValues(node->next);
        }
    }

    void redistributeValues(Node* node, int &idx)
    {
        if (!node) return;
        node->val = vals[idx++];

        if (node->child) {
            redistributeValues(node->child, idx);
        }

        if (node->next) {
            redistributeValues(node->next, idx);
        }
    }
};