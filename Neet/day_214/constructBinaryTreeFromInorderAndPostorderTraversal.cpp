class Solution 
{
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (inorder.empty() || postorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(postorder.back());
        int splitIdx = findIdxInorderArray(postorder.back(), inorder);

        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin()+splitIdx);
        vector<int> inorderRight = vector<int>(inorder.begin()+splitIdx+1, inorder.end());
        vector<int> postorderLeft = vector<int>(postorder.begin(), postorder.begin()+splitIdx);
        vector<int> postorderRight = vector<int>(postorder.begin()+splitIdx, postorder.end()-1);

        root->left = buildTree(inorderLeft, postorderLeft);
        root->right = buildTree(inorderRight, postorderRight);
        return root;
    }

    private:
    int findIdxInorderArray(int val, vector<int>& inorder)
    {
        int n = inorder.size();
        for (int i=0; i<n; i++) {
            if (val == inorder[i]) return i;
        }
        return -1;
    }
};