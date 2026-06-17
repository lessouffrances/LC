class Solution 
{
    public:
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        while (!q.empty()) {
            int size = q.size();
            long long currLevelSum = 0;
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                currLevelSum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            minHeap.push(currLevelSum);
            if (minHeap.size() > k) minHeap.pop();
        }
        if (minHeap.size() < k) return -1;
        return minHeap.top();
    }
};