

struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() : isEndOfWord(false), children( {} ) {}
};


class Trie 
{
    public:
    Trie() : root(new TrieNode()) {}
    
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
            if (!curr->children.count(ch)) {
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) {
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }
    private:
    TrieNode* root;
};
    
    