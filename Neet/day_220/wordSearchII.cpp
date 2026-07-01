struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    string word; // if word.empty() means no word ends with this node

    TrieNode() : children( {} ), word("") {}
};

class Trie 
{
    public:
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
        curr->word = word;
    }
};

class Solution 
{
    public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        ROW = board.size();
        COL = board[0].size();
        if (words.empty()) return {};

        // init a Trie and add all words into it
        Trie* trie = new Trie();
        for (auto& w : words) {
            trie->insert(w);
        }

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                dfs(r, c, trie->root, board);
            }
        }
        return res;
    }

    private:
    int ROW, COL;
    vector<string> res;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    void dfs(int row, int col, TrieNode* node, vector<vector<char>>& board)
    {
        if (row<0||row>=ROW||col<0||col>=COL) return;
        if (board[row][col] == '#') return;
        if (!node->children.count(board[row][col])) return;
        
        char originalChar = board[row][col];
        TrieNode* child = node->children[originalChar];
        
        if (!child->word.empty()) {
            res.push_back(child->word);
            child->word = "";
        }
        
        board[row][col] = '#';
        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;
            dfs(newR, newC, child, board);
        }
        board[row][col] = originalChar;
    }
};