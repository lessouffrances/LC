
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
        for (auto& w : products) insert(w);
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
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) return; // prefix
            curr = curr->children[ch];
        }
        collect(curr, prefix, suggestions);
    }

    void collect(TrieNode* node, string current, vector<string>& suggestions)
    {
        if (suggestions.size() == 3) return;
        if (node->isEndOfWord) suggestions.push_back(current);

        for (char ch='a'; ch<='z'; ch++) {
            if (node->children.count(ch)) {
                collect(node->children[ch], current+ch, suggestions);
            }
        }
    }

    bool search(const string& word)
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) return false;
            curr = curr->children[ch];
        }
        return curr->isEndOfWord;
    }

    bool startWith(const string& prefix)
    {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) return false;
            curr = curr->children[ch];
        }
        return true;
    }

    private:
    TrieNode* root = new TrieNode();
};