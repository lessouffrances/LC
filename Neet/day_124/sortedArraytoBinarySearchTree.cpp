


class Solution 
{
    public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if (nums.empty()) return nullptr;
        int left = 0, right = nums.size()-1;
        
        return buildBalancedBinaryTree(nums, left, right);
    }
    private:
    TreeNode* buildBalancedBinaryTree(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        int mid = left + (right-left) / 2;
        
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBalancedBinaryTree(nums, left, mid-1);
        node->right = buildBalancedBinaryTree(nums, mid+1, right);

        return node;
    }
};