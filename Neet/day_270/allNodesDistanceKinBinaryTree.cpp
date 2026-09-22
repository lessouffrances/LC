/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution 
 {
     public:
     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
     {
         if (!root) return {};
         // build parent
         dfsBuildParent(root);
 
         // seed target
         queue<TreeNode* > q;
         q.push(target);
         unordered_set<TreeNode* > visited;
         visited.insert(target);
 
         // BFS
         vector<int> res;
         int dist = 0;
         while (!q.empty()) {
             int size = q.size();
             for (int i=0; i<size; i++) {
                 auto currNode = q.front(); q.pop();
                 if (dist == k) {
                     res.push_back(currNode->val);
                 }
 
                 if (currNode->left && !visited.count(currNode->left)) {
                     q.push(currNode->left);
                     visited.insert(currNode->left);
                 }
                 if (currNode->right && !visited.count(currNode->right)) {
                     q.push(currNode->right);
                     visited.insert(currNode->right);
                 }
                 if (parent.count(currNode) && !visited.count(parent[currNode])) {
                     q.push(parent[currNode]);
                     visited.insert(parent[currNode]);
                 }
             }
             dist++;
         }
         return res;
     }
 
     private:
     unordered_map<TreeNode*, TreeNode*> parent;
 
     void dfsBuildParent(TreeNode* node)
     {
         if (!node) return;
 
         if (node->left) {
             parent[node->left] = node;
             dfsBuildParent(node->left);
         }
         if (node->right) {
             parent[node->right] = node;
             dfsBuildParent(node->right);
         }
     }
 };