




class Solution 
{
    public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (!head) return nullptr;

        ListNode* curr = head;
        vector<int> nums;
        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        return buildBalancedBinaryTree(nums, 0, nums.size()-1);
    }
    private:
    TreeNode* buildBalancedBinaryTree(vector<int>& nums, int left,  int right)
    {
        if (left > right) return nullptr;

        int mid = left + (right-left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = buildBalancedBinaryTree(nums, left, mid-1);
        node->right = buildBalancedBinaryTree(nums, mid+1, right);

        return node;
    }
};