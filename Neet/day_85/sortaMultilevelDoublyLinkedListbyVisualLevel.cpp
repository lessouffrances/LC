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
    Node* sortMultilevelLinkedListByVisualLevel(Node* head) 
    {
        if (!head) return nullptr;

        int startLevel = 0;
        dfsPerVisualLevel(head, startLevel);

        // sort by visual level
        for (auto& [level, nodes] : levelMap) {
            vector<int> currVals;
            for (auto& node : nodes) {
                currVals.push_back(node->val);
            }
            sort(currVals.begin(), currVals.end());

            // put back the currVals
            for (int i=0; i<nodes.size(); i++) {
                nodes[i]->val = currVals[i];
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