
struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    string word; 
    // if word.empty() means: no word ends with this node
};

class Trie
{
    public:
    Trie() : root(new TrieNode()) {}
    TrieNode* root;

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
        if (board.empty() || words.empty()) return {};
        ROW = board.size();
        COL = board[0].size();

        Trie* trie = new Trie();
        for (auto& word : words) {
            trie->insert(word);
        }

        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                // try each char as the starting of 
                // one word to see there's any match
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
        // mark visited
        char originalChar = board[row][col];
        // check before accessing children to avoid null pointer
        if (!node->children.count(originalChar)) {
            return;
        }
        board[row][col] = '#';
        TrieNode* child = node->children[originalChar];

        if (!child->word.empty()) {
            res.push_back(child->word);
            child->word = "";
            // cannot return here!
        }

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;
            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (board[newR][newC] == '#') continue;
            if (!child->children.count(board[newR][newC])) continue;

            dfs(newR, newC, child, board);
        }
        board[row][col] = originalChar;
    }
};
