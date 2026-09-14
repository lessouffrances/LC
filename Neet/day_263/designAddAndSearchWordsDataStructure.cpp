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
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) 
    {
        return dfs(0, root, word);
    }

    private:
    TrieNode* root = new TrieNode();

    bool dfs(int currIdx, TrieNode* node, const string& word)
    {
        if (currIdx == word.length() && node->isEndOfWord) return true;
        if (currIdx == word.length()) return false;

        char currCh = word[currIdx];
        for (auto& [c, nextNode] : node->children) {
            if (currCh == '.' || currCh == c) {
                if dfs(currIdx+1, nextNode, word) return true;
            }
        }
        return false;
    }
};
    
   