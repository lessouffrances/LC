


struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode* > children;
};

class WordDictionary 
{
    public:
    WordDictionary() {}
    
    void addWord(string word) 
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
    
    bool search(string word) 
    {
        return dfs(root, 0, word);
    }
    private:
    TrieNode* root = new TrieNode();

    bool dfs(TrieNode* node, int idx, const string& word)
    {
        if (idx == word.length()) {
            return node->isEndOfWord;
        }

        // recurse
        char ch = word[idx];
        for (auto& [c, nextNode] : node->children) {
            if (ch == '.' || ch == c) {
                // can skip
                if (dfs(nextNode, idx+1, word)) return true;
            } 
        }
        return false;
    }
};
    
   