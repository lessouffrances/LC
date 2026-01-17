class Solution 
{
    public:
    // BFS is the most intuitive solu
    int amountOfTime(TreeNode* root, int start) 
    {
        if (!root) return 0;
        buildParentMarkStart(root, start);
        bfs(startNode);
        return minutes;
    }
    private:
    TreeNode* startNode;
    int minutes = 0;
    unordered_map<TreeNode*, TreeNode*> parent; // { child : parent }
    void bfs(TreeNode* node) 
    {
        if (!node) return;

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(node);
        visited.insert(node);

        while (!q.empty()) {
            int size = q.size();
            bool infected = false;

            for (int i=0; i<size; i++) {
                auto frontNode = q.front();
                q.pop();

                if (frontNode->left && !visited.count(frontNode->left)) {
                    q.push(frontNode->left);
                    visited.insert(frontNode->left);
                    infected = true;
                }
                if (frontNode->right && !visited.count(frontNode->right)) {
                    q.push(frontNode->right);
                    visited.insert(frontNode->right);
                    infected = true;
                }
                if (parent.count(frontNode) && !visited.count(parent[frontNode])) {
                    q.push(parent[frontNode]);
                    visited.insert(parent[frontNode]);
                    infected = true;
                }
            }
            if (infected) minutes++;
        }
    }

    void buildParentMarkStart(TreeNode* node, int start)
    {
        if (!node) return;

        buildParentMarkStart(node->left, start);
        buildParentMarkStart(node->right, start);

        if (node->left) {
            parent[node->left] = node;
        }
        if (node->right) {
            parent[node->right] = node;
        }
        if (node->val == start) {
            startNode = node;
        }
    }
};