





// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
class Solution 
{
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (inorder.empty() || postorder.empty()) return nullptr;

        // get root val
        int rootVal = postorder.back();
        TreeNode* root = new TreeNode(rootVal);
        // get splitIdx in inorder
        int splitIdx = getRootIdx(inorder, rootVal);
        
        // recurse on left
        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin()+splitIdx);
        vector<int> postorderLeft = vector<int>(postorder.begin(), postorder.begin()+splitIdx);
        root->left = buildTree(inorderLeft, postorderLeft);
        
        // recurse on right
        vector<int> inorderRight = vector<int>(inorder.begin()+splitIdx+1, inorder.end());
        vector<int> postorderRight = vector<int>(postorder.begin()+splitIdx, postorder.end()-1);
        root->right = buildTree(inorderRight, postorderRight);

        return root;
    }
    int getRootIdx(vector<int> inorder, int rootVal)
    {
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == rootVal) return i;
        }
        return -1;
    }
};