

// Time Complexity:
// O(n), n is the size of the input

// Space Complexity:
// O(m * n)
struct TrieNode
{
    unordered_map<char, TrieNode* > children;
    bool isEndOfWord;

    TrieNode() : children( {} ), isEndOfWord(false) {}
};

class Trie
{
    private:
    TrieNode* root;
    
    public:
    Trie() : root( new TrieNode() ) {}

    void insert(string word) 
    {
        TrieNode* curr = root; // go from the top of the Trie

        // iterate thru all char
        for (char ch : word) {
            // if this node's children DO NOT has char, do:
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            // go down the Trie
            curr = curr->children[ch];
        }
        // done iterating:
        curr->isEndOfWord = true;
    }
    
    bool search(string word) 
    {
        TrieNode* curr = root; // go from the top of the Trie

        // iterate thru all char
        for (char ch : word) {
            // if this node's children DO NOT has char, do:
            if (!curr->children.count(ch)) {
                retun false; 
            }
            // go down the Trie
            curr = curr->children[ch];
        }
        // done iterating:
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* curr = root; // go from the top of the Trie

        // iterate thru all char
        for (char ch : word) {
            // if this node's children DO NOT has char, do:
            if (!curr->children.count(ch)) {
                retun false; 
            }
            // go down the Trie
            curr = curr->children[ch];
        }
        // done iterating:
        return true;
    }
};
    
    