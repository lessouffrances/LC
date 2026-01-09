struct TrieNode 
{
   map<string, TrieNode*> children;
   bool endOfWord;
   public:
   TrieNode()
   {
      children = {};
      endOfWord = false; 
   }
};

class Trie
{
   public:
   TrieNode* root;
   Trie() 
   {
      root = new TrieNode();
   }
  
   void insert(const string& word)
   { 
      TrieNode* curr = root;
      string currStr = "";
      for (char c : word) {
         if (c == '/') {
            if (!curr->children.count(currStr)) {
                curr->children[currStr] = new TrieNode();
            }
            curr = curr->children[currStr];
            currStr = "";
            continue;
         }
         currStr += c;
      }
      if (!currStr.empty()) {
         if (!curr->children.count(currStr)) {
               curr->children[currStr] = new TrieNode();
         }
         curr = curr->children[currStr];
      }
      curr->endOfWord = true;
   }
};
class Solution 
{
public:
   vector<string> removeSubfolders(vector<string>& folder) {
      if (folder.empty()) return {};

      Trie* fileSystem = new Trie();
      for (auto& fo : folder) {
         fileSystem->insert(fo);
      }
      string startStr = "";
      dfs(fileSystem->root, startStr);
      for (int i=0; i<res.size(); i++) {
        res[i] = string(res[i].begin()+1, res[i].end());
      }
      return res;
   }
private:
   vector<string> res;
   void dfs(TrieNode* node, string& currStr)
   {
      if (!node) return;
      if (node->endOfWord) {
         res.push_back(currStr);
         return;
      }

      for (auto [segment, childNode] : node->children) {
         currStr += ("/"+ segment);
         dfs(childNode, currStr);
         currStr.resize(currStr.size() - segment.size() - 1);
      }
   }
};
