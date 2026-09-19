
// preorder means the root is the first
//
class Solution 
{
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int splitIdx = getIdxInorder(preorder[0], inorder);

        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin()+splitIdx);
        vector<int> inorderRight = vector<int>(inorder.begin()+splitIdx+1, inorder.end());
        vector<int> preorderLeft = vector<int>(preorder.begin()+1, preorder.begin()+splitIdx+1);
        vector<int> preorderRight = vector<int>(preorder.begin()+splitIdx+1, preorder.end());

        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }

    private:
    int getIdxInorder(int val, vector<int>& inorder)
    {
        int n = inorder.size();
        for (int i=0; i<n; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }
};