
struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
};

class Solution 
{
    private:
    TrieNode* root = new TrieNode();

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

    // go down the Trie, once we find 2 children, exit:
    string getCommonPrefix()
    {
        string prefix = "";
        TrieNode* curr = root;

        while (curr->children.size() == 1 && !curr->isEndOfWord) {
            auto it = curr->children.begin(); 
            prefix += it->first; // append the ch
            curr = it->second; // go down 
        }
        return prefix;
    }

    public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        // insert all words into Trie
        for (auto str : strs) {
            insert(str);
        }

        return getCommonPrefix();
    }
};