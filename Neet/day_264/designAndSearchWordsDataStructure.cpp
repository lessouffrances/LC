struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEndOfWord(false), children( {} ) {}
    TrieNode(bool isEndOfWord) : isEndOfWord(isEndOfWord), children( {} ) {}
};

class WordDictionary 
{
    public:
    WordDictionary() {}
    
    void addWord(string word) 
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) curr->children[ch] = new TrieNode();
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
    bool dfs(TrieNode* node, int currIdx, const string& word)
    {
        if (currIdx == word.length() && node->isEndOfWord) return true;
        if (currIdx == word.length()) return false;
        char currCh = word[currIdx];
        for (auto& [ch, nextNode] : node->children) {
            if (currCh == '.' || currCh == ch) {
                if (dfs(nextNode, currIdx+1, word)) return true;
            }
        }
        return false;
    }
};
    
   