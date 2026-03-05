

struct TrieNode
{
    bool isEndOfWord = false;
    unordered_map<char, TrieNode* > children;
};

class WordDictionary 
{
    public:
    WordDictionary() {}
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return dfs(root, 0, word);
    }

    private:
    TrieNode* root = new TrieNode();

    bool dfs(TrieNode* node, int idx, const string& word)
    {
        if (idx == word.length()) return node->isEndOfWord;

        char ch = word[idx];
        if (ch == '.') {
            // skip this layer
            for (auto& [c, nextNode] : node->children) {
                if (dfs(nextNode, idx+1, word)) return true;
            }
            return false;
        
        } else {
            // this layer is not a match 
            if (!node->children.count(ch)) return false;

            // this layer is a match 
            return dfs(node->children[ch], idx+1, word);
        }
    }
};
    
    