class Codec
{
    public:
    string pwd = "";

    string serialize(TreeNode* root)
    {
        pwd = "";
        if (!root) return "";
        dfsEncode(root);
        return pwd;
    }

    TreeNode* deserialize(string data)
    {
        if (data.empty()) return nullptr;
        idx = 0;
        vector<string> dataStream = splitByStream(data, ',');
        return dfsDecode(dataStream);
    }

    private:
    int idx = 0;
    void dfsEncode(TreeNode* node)
    {
        if (!node) {
            pwd += "N,";
            return;
        }
        pwd += to_string(node->val) + ',';
        dfsEncode(node->left);
        dfsEncode(node->right);
    }

    TreeNode* dfsDecode(vector<string>& data)
    {
        // base case
        if (idx >= data.size() || data[idx] == "N") {
            idx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(data[idx]));
        idx++;
        node->left = dfsDecode(data);
        node->right = dfsDecode(data);
        return node;
    }

    vector<string> splitByStream(const string& data, char delimiter)
    {
        vector<string> tokens;
        string token;
        stringstream ss(data);

        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};