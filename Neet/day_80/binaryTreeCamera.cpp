enum State
{
    COVERED = 0,
    NOT_COVERED = 1,
    HAS_CAMERA = 2
};

class Solution 
{
    public:
    int minCameraCover(TreeNode* root) 
    {
        if (!root) return 0;
        int rootState = dfs(root);
        if (rootState == NOT_COVERED) {
            camera++;
        } 
        return camera;
    }
    private:
    int camera = 0;
    // post order
    int dfs(TreeNode* node) 
    {
        if (!node) return COVERED;

        int left = dfs(node->left);
        int right = dfs(node->right);

        // check if we should put a camera on this node
        if (left == NOT_COVERED || right == NOT_COVERED) {
            camera++;
            return HAS_CAMERA;
        }

        if (left == HAS_CAMERA || right == HAS_CAMERA) {
            return COVERED;
        }

        return NOT_COVERED;
    }
};