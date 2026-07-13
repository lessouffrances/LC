struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    int wordIdx;
    vector<int> palindromeSuffixes;

    TrieNode() : children({}), wordIdx(-1) {}
};

class Trie
{
    public:
    Trie() {}

    void insert(const string& word, int idx) {
        TrieNode* curr = root;
        int n = word.size();
        for (int j = n-1; j >= 0; j--) {
            if (isPalin(word, 0, j))
                curr->palindromeSuffixes.push_back(idx);
            char ch = word[j];
            if (!curr->children.count(ch))
                curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->wordIdx = idx;
        curr->palindromeSuffixes.push_back(idx);
    }

    void search(const string& word, int i, set<vector<int>>& res) {
        TrieNode* curr = root;
        int n = word.size();
        for (int j = 0; j < n; j++) {
            if (curr->wordIdx != -1 && curr->wordIdx != i
                && isPalin(word, j, n-1))
                res.insert({i, curr->wordIdx});
            if (!curr->children.count(word[j])) return;
            curr = curr->children[word[j]];
        }
        if (curr->wordIdx != -1 && curr->wordIdx != i)
            res.insert({i, curr->wordIdx});
        for (int idx : curr->palindromeSuffixes)
            if (idx != i) res.insert({i, idx});
    }

    private:
    TrieNode* root = new TrieNode();

    bool isPalin(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
};

class Solution 
{
    public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        Trie trie;
        for (int i = 0; i < (int)words.size(); i++)
            trie.insert(words[i], i);

        set<vector<int>> resSet;
        for (int i = 0; i < (int)words.size(); i++)
            trie.search(words[i], i, resSet);

        return vector<vector<int>>(resSet.begin(), resSet.end());
    }
};