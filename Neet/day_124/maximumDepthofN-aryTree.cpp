




class Solution 
{
    public:
    int maxDepth(Node* root) 
    {
        return dfs(node);
    }

    // postorder
    long long dfs(Node* node)
    {
        if (!node) return 0;

        long long maxHeight = 0;
        for (auto& child : children) {
            maxHeight = max(maxHeight, dfs(child));
        } 

        return 1 + maxHeight;
    } 
};