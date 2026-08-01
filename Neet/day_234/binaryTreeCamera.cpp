enum Status 
{
    COVERED = 0,
    NOT_COVERED = 1,
    HAS_CAMERA = 2
}

class Solution 
{
    public:
    int minCameraCover(TreeNode* root) 
    {
        int rootStatus = dfs(root);
        if (rootStatus == NOT_COVERED) res++;
        return res;
    }

    private:
    // bottom-up, post-order
    int res = 0;
    int dfs(TreeNode* node)
    {
        if (!node) return COVERED;
        int leftStatus = dfs(node->left);
        int rightStatus = dfs(node->right);

        // has to make a decision: should we put a camera on this node?
        if (leftStatus == NOT_COVERED || rightStatus == NOT_COVERED) {
            // put a camera
            res++;
            return HAS_CAMERA;
        }
        if (leftStatus == HAS_CAMERA || rightStatus == HAS_CAMERA) {
            return COVERED;
        }
        return NOT_COVERED;
    }
};