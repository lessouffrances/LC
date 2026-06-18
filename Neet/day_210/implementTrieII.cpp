struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
    int count; // number of words ending at this char

    TrieNode() : isEndOfWord(false), count(0) {}
};

class Trie
{
    public:
    Trie() : root( new TrieNode() ) {}

    void insert(const string& word)
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->count++;
        curr->isEndOfWord = true;
    }

    int countWordsEqualTo(const string& word)
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) return 0;
            curr = curr->children[ch];
        }
        return curr->count;
    }

    int countWordsStartingWith(const string& word)
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) return 0;
            curr = curr->children[ch];
        }
        return dfs(curr);
    }

    void erase(const string& word)
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) return;
            curr = curr->children[ch];
        }
        curr->count--;
        if (curr->count == 0) curr->isEndOfWord = false;
    }

    private:
    TrieNode* root;

    int dfs(TrieNode* node)
    {
        int total = node->count;
        for (auto& [ch, nextNode] : node->children) {
            total += dfs(nextNode);
        }
        return total;
    }
};
