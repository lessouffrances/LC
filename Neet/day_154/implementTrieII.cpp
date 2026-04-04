


struct TrieNode
{
    bool isEndOfWord;
    int count; // count number of words ending here
    unordered_map<char, TrieNode*> children;
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
        curr->count++;
        curr->isEndOfWord = true;
    }
    
    int countWordsEqualTo(string word) 
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) {
                return 0;
            }
            curr = curr->children[ch];
        }
        return curr->count;
    }
    
    int countWordsStartingWith(string prefix) 
    {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) {
                return 0;
            }
            curr = curr->children[ch];
        }

        return dfs(curr);
    }
    
    // just set the boolean of the end char to be false
    void erase(string word) 
    {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) return;
            curr = curr->children[ch];
        }
        curr->count--;
        curr->isEndOfWord = false;
    }

    private:
    TrieNode* root;

    int dfs(TrieNode* node) {
        int total = node->count;
        for (auto& [ch, child] : node->children) {
            total += dfs(child);
        }
        return total;
    }
};
    
  