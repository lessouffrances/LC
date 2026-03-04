

// after learning this solution, replace the unordered_map with a vector
struct TrieNode
{
    bool isEndOfWord = false;
    unordered_map<char, TrieNode*> children;
};

class WordDictionary 
{
    public:
    WordDictionary() {}

    void addWord(string word) 
    {
        // starting point
        TrieNode* curr = root;
        // iterate the word 
        for (char ch : word) {
            // if this char is not at this layer, do:
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            // go down the Trie
            curr = curr->children[ch];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) 
    {
        return dfs(root, 0, word);
    }

    private:
    // init the root
    TrieNode* root = new TrieNode();

    bool dfs(TrieNode* node, int idx, const string& word)
    {
        if (idx == word.length()) return node->isEndOfWord;

        char ch = word[idx];
        if (ch == '.') {
            // skip this layer of trie, go to the next layer
            for (auto& [c, trieNode] : node->children) {
                if (dfs(trieNode, idx+1, word)) return true;
            }
            return false;
        } else {
            // not a match for this layer
            if (!node->children.count(ch)) return false;
            // is a match for this layer
            return dfs(node->children[ch], idx+1, word);
        }
    }
};