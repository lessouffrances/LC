// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
class Solution 
{
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        // find the idx of this root in inorder array, which is a split point
        int splitIdx = getIdxInorder(inorder, preorder[0]);

        // recurse on left
        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin()+splitIdx);
        vector<int> preorderLeft = vector<int>(preorder.begin()+1, preorder.begin()+splitIdx+1);
        root->left = buildTree(preorderLeft, inorderLeft);

        // recurse on right
        vector<int> inorderRight = vector<int>(inorder.begin()+splitIdx+1, inorder.end());
        vector<int> preorderRight = vector<int>(preorder.begin()+splitIdx+1, preorder.end());
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
    private:
    int getIdxInorder(vector<int>& inorder, int val) {
        if (inorder.empty()) return -1;

        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
};