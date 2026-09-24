

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
};

class Solution 
{
    public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        if (products.empty()) return {};

        // build the Trie
        for (auto& p : products) {
            insert(p);
        }   
        
        // for each prefix in searchWord, do a dfs to collect all the words in the Trie
        // that has the prefix 
        vector<vector<string>> res;
        string prefix = "";
        for (char ch : searchWord) {
            prefix += ch;
            vector<string> suggestions;
            travelToTheEndOfPrefixAndCollect(prefix, suggestions);
            res.push_back(suggestions);
        }
        return res;
    }

    private:
    void travelToTheEndOfPrefixAndCollect(const string& prefix, vector<string>& suggestions)
    {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) return;
            curr = curr->children[ch];
        }

        // here the curr would be at the end of the prefix
        dfs(curr, prefix, suggestions);
    }

    void dfs(TrieNode* node, string currPath, vector<string>& suggestions)
    {
        if (suggestions.size() == 3) return;
        if (node->isEndOfWord) suggestions.push_back(currPath);

        for (char ch='a'; ch<='z'; ch++) {
            if (node->children.count(ch)) {
                dfs(node->children[ch], currPath+ch, suggestions);
            }
        }
    }

    // Trie Util
    TrieNode* root = new TrieNode();
    void insert(const string& s) 
    {
        TrieNode* curr = root;
        for (char ch : s) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEndOfWord = true;
    }
};