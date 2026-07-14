class Solution 
{
    public:
    string alienOrder(vector<string>& words) 
    {
        // these two are productively important
        if (words.empty() || !buildGraph(words)) return "";

        // FULL-dfs finding DAG
        for (auto& [node, _ ] : graph) {
            if (visited.count(node)) continue;
            if (dfsHasCycle(node)) return "";
        }

        reverse(finishingOrder.begin(), finishingOrder.end());
        return string(finishingOrder.begin(), finishingOrder.end());
    }

    private:
    unordered_map<char, vector<char>> graph;
    unordered_set<char> visited;
    unordered_set<char> ancestorStack;
    vector<char> finishingOrder;

    // if has cycle, return true
    bool dfsHasCycle(char u)
    {
        ancestorStack.insert(u);
        visited.insert(u);

        for (char v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            if (dfsHasCycle(v)) return true;
        }

        ancestorStack.erase(u);
        finishingOrder.push_back(u);
        return false;
    }

    // sometimes we are not sure if there are the valid sequence, valid DAG
    bool buildGraph(vector<string>& words)
    {
        if (words.empty()) return false;
        int n = words.size();

        // loop thru each pair
        for (int i=1; i<n; i++) {
            string word1 = words[i-1];
            string word2 = words[i];

            // invalid case
            int minLen = min(word1.length(), word2.length());
            if (word1.length() > word2.length() 
                && word1.substr(0, minLen) == word2.substr(0, minLen)) return false;

            for (int j=0; j<minLen; j++) {
                if (word1[j] != word2[j]) {
                    // an effective edge
                    // if char are put at the same pos, 
                    // then the one that in i-1 comes higher
                    graph[word1[j]].push_back(word2[j]);
                    break;
                }
            }
        }

        for (auto& word : words) {
            for (char ch : word) {
                if (!graph.count(ch)) graph[ch] = {};
            }
        }
        return true;
    }
};