// Definition for a Node.
class Node 
{
    public:
    int val;
    Node* next;
    Node* child;
};
    
    
class Solution 
{
    public:
    Node* sortMultilevelLinkedList(Node* head) 
    {
        if (!head) return nullptr;

        // collect the values
        collectVals(head);

        // sort
        sort(vals.begin(), vals.end());

        // populate the values
        int startIdx = 0;
        populateVals(head, startIdx);

        return head;
    }

    private:
    vector<int> vals;
    void populateVals(Node* node, int& idx) 
    {
        if (!node) return;

        node->val = vals[idx];
        idx++;

        if (node->child) {
            populateVals(node->child, idx);
        }
        if (node->next) {
            populateVals(node->next, idx);
        }
    }

    void collectVals(Node* node) 
    {
        if (!node) return;
        vals.push_back(node->val);

        if (node->child) {
            collectVals(node->child);
        }
        if (node->next) {
            collectVals(node->next);
        }
    }
};