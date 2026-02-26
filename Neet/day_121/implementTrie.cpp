struct TrieNode
{
    map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : children({}), isEndOfWord(false) {}
};

class Trie
{
    public:
    Trie() : root(new TrieNode()) {}

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

    bool search(const string& word) 
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

    bool startsWith(const string& word)
    {
        TrieNode* curr = root;
        for (char ch : word) {
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

8664281098