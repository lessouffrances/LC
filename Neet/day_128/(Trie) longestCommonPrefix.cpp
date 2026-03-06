
struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode* > children;
};

class Solution 
{
    public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        for (auto& str : strs) {
            insert(str);
        }

        TrieNode* curr = new TrieNode();
        string prefix = "";
        while (curr->children.size() == 1) {
            prefix += curr->children.begin()->first;
            curr = curr->children.begin()->second;
        }
        return prefix;
    }

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
};