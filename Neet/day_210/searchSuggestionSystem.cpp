struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
};

class Solution 
{
    public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        if (products.empty() || searchWord.length() == 0) return { {} };
        for (auto& p : products) {
            insert(p);
        }

        vector<vector<string>> res;
        string prefix = "";

        for (char ch : searchWord) {
            prefix += ch;
            vector<string> suggestions;
            dfs(prefix, suggestions);
            res.push_back(suggestions);
        }
        return res;
    }

    private:
    TrieNode* root = new TrieNode();

    void insert(const string& word)
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEndOfWord = true;
    }

    void dfs(const string& prefix, vector<string>& suggestions)
    {
        // walk to the end of this prefix
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) return;
            curr = curr->children[ch];
        }
        collect(curr, prefix, suggestions); 
    }

    void collect(TrieNode* node, string currPath, vector<string>& suggestions)
    {
        if (suggestions.size() == 3) return;
        if (node->isEndOfWord) suggestions.push_back(currPath);
        for (char ch='a'; ch<='z'; ch++) {
            if (node->children.count(ch)) {
                collect(node->children[ch], currPath+ch, suggestions);
            }
        }
    }
};