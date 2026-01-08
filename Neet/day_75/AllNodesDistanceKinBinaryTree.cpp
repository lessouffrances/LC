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
   // bfs to find the second layer
   vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
   {
      if (!root) return {};
      // find the source
      findTargetBuildParentPointer(root, target->val);
      return bfs(source, k);
   }

private:
   // standard bfs 
   vector<int> bfs(TreeNode* source, int k)
   {
      if (!source) return {};
      if (k == 0) return { source->val };
      set<TreeNode*> visited;
      visited.insert(source);
      queue<TreeNode*> q;

      if (source->left) {
         q.push(source->left);
         visited.insert(source->left);
      }
      if (source->right) {
         q.push(source->right);
         visited.insert(source->right);
      }
      if (parent.count(source)) {
         q.push(parent[source]);
         visited.insert(parent[source]);
      } 
 
      while (!q.empty()) { 
         k--;
         int size = q.size();
         vector<int> res;
         for (int i=0; i<size; i++) {
            auto node = q.front();
            q.pop();
            if (k == 0) {
               res.push_back(node->val);
            } else {
               if (node->left && !visited.count(node->left)) {
                   visited.insert(node->left);
                   q.push(node->left);
               }
               if (node->right && !visited.count(node->right)) {
                   visited.insert(node->right);
                   q.push(node->right);
               }
               if (parent.count(node) && !visited.count(parent[node])) {
                   visited.insert(parent[node]);
                   q.push(parent[node]);
               }
            }
         }
         if (k==0) return res;
      }
      return {};
   }
   

   // preorder to find the target
   unordered_map<TreeNode*, TreeNode*> parent;
   TreeNode* source;
   void findTargetBuildParentPointer(TreeNode* root, int target) 
   {
      if (!root) return;
      if (root->val == target) {
         source = root; // attach target
      }
      if (root->left) {
         parent[root->left] = root;
      }
      if (root->right) {
         parent[root->right] = root;
      }
      findTargetBuildParentPointer(root->left, target);
      findTargetBuildParentPointer(root->right, target);
   }
};
