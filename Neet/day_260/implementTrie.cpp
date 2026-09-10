struct TrieNode
{
    bool isEndOfWord = false;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEndOfWord(false), children( {} ) {}
};

class Trie 
{
    private:
    TrieNode* root = new TrieNode();

    public:
    Trie() {}
    
    void insert(string word) 
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
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) return false;
            curr = curr->children[ch];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) return false;
            curr = curr->children[ch];
        }
        return true;
    }
};
   