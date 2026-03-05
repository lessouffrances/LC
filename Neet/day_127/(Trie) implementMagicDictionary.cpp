

struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
};

class MagicDictionary 
{
    public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) 
    {
        for (auto& word : dictionary) {
            insert(word);
        }
    }
    
    bool search(const string& searchWord) 
    {
        return dfs(root, 0, 0, searchWord);  
    }

    private:
    TrieNode* root = new TrieNode();
    bool dfs(TrieNode* node, int idx, int diff, const string& word) 
    {
        if (diff > 1) return false;

        if (idx == word.length()) {
            return node->isEndOfWord && diff == 1;
        }

        char ch = word[idx];
        for (auto& [c, nextNode] : node->children) {
            int nextDiff = diff + ((ch == c) ? 0 : 1);
            if (dfs(nextNode, idx+1, nextDiff, word)) return true;
        }
        return false;
    }

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
};
    
   