

class Solution 
{
    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if (!root) return {};
        parent[root] = nullptr;
        dfsMarkTagetAndBuildParent(root);
        // seed target node
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int dist = 0;
        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto node = q.front(); q.pop();
                
                if (dist == k) {
                    res.push_back(node->val);
                }
                if (node->left && !visited.count(node->left)) {
                    q.push( node->left ); 
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    q.push( node->right ); 
                    visited.insert(node->right);
                }
                if (parent[node] && !visited.count(parent[node])) {
                    q.push(parent[node]); 
                    visited.insert(parent[node]);
                } 
            }
            if (!res.empty()) return res;
            dist++;
        }
        return {};
    }

    private:
    unordered_map<TreeNode*, TreeNode*> parent; // { child, parent }
    void dfsMarkTagetAndBuildParent(TreeNode* node)
    {
        if (!node) return;

        if (node->left) {
            parent[node->left] = node;
            dfsMarkTagetAndBuildParent(node->left);
        } 
        if (node->right) {
            parent[node->right] = node;
            dfsMarkTagetAndBuildParent(node->right);
        }
    }
};