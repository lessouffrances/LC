





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
        // build the trie
        for (auto& f : folder) {
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
        }

        for (auto& [seg, child] : node->children) {
            string part = '/' + seg;
            currPath += part;
            dfs(child, currPath);
            currPath.erase(currPath.size()-part.size());
        }
    }

    void insert(string word)
    {
        stringstream ss(word);
        string token;
        vector<string> nodes;
        while (getline(ss, token, '/')) {
            if (!token.empty()) {
                nodes.push_back(token);
            }
        }

        TrieNode* curr = root;
        for (auto& seg : nodes) {
            if (!curr->children[seg]) {
                curr->children[seg] = new TrieNode();
            }
            curr = curr->children[seg];
        }
        curr->isEndOfWord = true;
    }
};