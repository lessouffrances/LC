class Solution 
{
    public:
    // bfs to find the second layer
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        markSourceAndConstructParentMap(root, target->val);
        return bfs(sourceForBFS, k);
    }
    
    private:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* sourceForBFS;
    vector<int> bfs(TreeNode* source, int k) 
    {
        queue<TreeNode*> q;
        q.push(source);
        set<TreeNode*> visited;
        visited.insert(source);

        vector<int> res;
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                if (k == 0) {
                    found = true;
                    res.push_back(node->val);
                }

                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parent.count(node) && parent[node] && !visited.count(parent[node])) {
                q.push(parent[node]);
                visited.insert(parent[node]);
            }
            }
            if (found) break;
            k--;
        }
        return res;
    }

    // preorder traversal 
    void markSourceAndConstructParentMap(TreeNode* node, int target)
    {
        if (!node) return;

        if (node->left) {
            parent[node->left] = node;
        }
        if (node->right) {
            parent[node->right] = node;
        }
        if (node->val == target) {
            sourceForBFS = node;
        }

        markSourceAndConstructParentMap(node->left, target);
        markSourceAndConstructParentMap(node->right, target);
    }
};