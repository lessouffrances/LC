

struct TrieNode
{
    bool isEndOfWord;
    unordered_map<string, TrieNode*> children;

    TrieNode() : isEndOfWord(false), children( {} ) {}
};

class Solution 
{
    public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        // insert all folders to the Trie
        for (auto & f : folder) {
            insert(f);
        }

        string currPath = "";
        dfs(root, currPath);
        return res;
    }

    private:
    TrieNode* root = new TrieNode();
    vector<string> res;

    void dfs(TrieNode* node, string& currPath)
    {
        if (node->isEndOfWord) {
            res.push_back(currPath);
            return;
        };

        for (auto& [seg, child] : node->children) {
            string part = '/' + seg;
            currPath += part;
            dfs(child, currPath);
            currPath.erase(currPath.size()-part.size());
        }
    }

    // insert a path
    void insert(const string& word) 
    {
        stringstream ss(word);
        vector<string> nodes;
        string token;
        while (getline(ss, token, '/')) {
            if (!token.empty()) {
                nodes.push_back(token);
            }            
        }

        TrieNode* curr = root;
        for (string node : nodes) {
            if (!curr->children.count(node)) {
                curr->children[node] = new TrieNode();
            }
            curr = curr->children[node];
        }
        curr->isEndOfWord = true;
    } 
};