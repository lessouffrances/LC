class BSTIterator 
{
    public:
    BSTIterator(TreeNode* root) 
    {
        dfsInorder(root);
    }
    
    int next() 
    {
        currIdx++;
        int res = vals[currIdx];
        return res;
    }
    
    bool hasNext() 
    {
        return currIdx < (int)(vals.size()-1);
    }

    private:
    int currIdx = -1;
    vector<int> vals;
    void dfsInorder(TreeNode* node)
    {
        if (!node) return;

        dfsInorder(node->left);
        vals.push_back(node->val);
        dfsInorder(node->right);
    }
};
