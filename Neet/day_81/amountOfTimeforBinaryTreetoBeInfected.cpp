struct TreeNode
 {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution 
{
    public:
    // BFS is the most intuitive solu
    int amountOfTime(TreeNode* root, int start) 
    {
        if (!root) return 0;
        buildParentAndMarkStart(root, start);
        bfs(startNode);
        return minutes;
    }

    private:
    TreeNode* startNode = nullptr;
    int minutes = 0;
    unordered_map<TreeNode*, TreeNode*> parent; // { child : parent }
    unordered_set<TreeNode*> visited;
    void bfs(TreeNode* node) 
    {
        if (!node) return;

        queue<TreeNode*> q;
        q.push(node);
        visited.insert(node);

        while (!q.empty()) {
            int size = q.size();
            bool infected = false;
            for (int i=0; i<size; i++) {
                auto frontNode = q.front();
                q.pop();

                if (frontNode->left && visited.find(frontNode->left) == visited.end()) {
                    q.push(frontNode->left);
                    visited.insert(frontNode->left);
                    infected = true;
                } 
                if (frontNode->right && visited.find(frontNode->right) == visited.end()) {
                    q.push(frontNode->right);
                    visited.insert(frontNode->right);
                    infected = true;
                } 
                if (parent.count(frontNode) && visited.find(parent[frontNode]) == visited.end()) {
                    q.push(parent[frontNode]);
                    visited.insert(parent[frontNode]);
                    infected = true;
                } 
            }
            if (infected) minutes++;
        }
    }

    void buildParentAndMarkStart(TreeNode* node, int start)
    { 
        if (!node) return;

        buildParentAndMarkStart(node->left, start);
        buildParentAndMarkStart(node->right, start);

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