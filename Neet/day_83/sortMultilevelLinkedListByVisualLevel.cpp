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
        dfsPerVisualLevel(head, 0);

        // sort by visual level
        for (auto& [level, nodes] : levelMap) {
            // collect
            vector<int> vals;
            for (auto& node : nodes) {
                vals.push_back(node->val);
            }

            // sort
            sort(vals.begin(), vals.end());

            // put back
            for (int i=0; i<nodes.size(); i++) {
                nodes[i]->val = vals[i];
            }
        }

        return head;
    }

    private:
    unordered_map<int, vector<Node*>> levelMap;
    void dfsPerVisualLevel(Node* node, int level)
    {
        if (!node) return;
        levelMap[level].push_back(node);

        if (node->next) {
            dfsPerVisualLevel(node->next, level);
        }

        if (node->child) {
            dfsPerVisualLevel(node->child, level+1);
        }        
    }
};