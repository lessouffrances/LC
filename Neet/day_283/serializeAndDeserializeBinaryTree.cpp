class Codec 
{
    public:
    // Encodes a tree to a single string.

    string serialize(TreeNode* root) 
    {
        passcode = "";
        encode(root);
        return passcode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        idx = 0;
        vector<string> tokens = tokenize(data, ',');
        return decode(tokens);
    }

    private:
    string passcode = "";
    int idx = 0;

    void encode(TreeNode* node)
    {
        if (!node) {
            passcode += "N,";
            return;
        }

        passcode += to_string(node->val) + ",";
        encode(node->left);
        encode(node->right);
    }

    TreeNode* decode(vector<string>& tokens)
    {
        if (idx >= tokens.size() || tokens[idx] == "N") {
            idx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(tokens[idx]));
        idx++;
        node->left = decode(tokens);
        node->right = decode(tokens);

        return node;
    }

    vector<string> tokenize(const string& s, char delimiter) 
    {
        stringstream ss(s);
        vector<string> tokens;
        string token;
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

