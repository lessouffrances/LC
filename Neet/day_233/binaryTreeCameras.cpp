class Solution 
{
    public:
    int minCameraCover(TreeNode* root) 
    {
        if (!root) return 0;
        int rootState = dfs(root);
        if (rootState == 1) camera++;
        return camera;
    }

    private:
    int camera = 0;
    // return status: 0, COVERED; 
    //                1, NOT_COVERED; 
    //                2, HAS_CAMERA;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int leftState = dfs(node->left);
        int rightState = dfs(node->right);

        // check if we should put a camera on this node
        // case 1: left or right child not covered
        if (leftState == 1 || rightState == 1) {
            camera++;
            return 2;
        }
        // case 2: 
        if (leftState == 2 || rightState == 2) {
            return 0;
        }
        return 1;
    }
};