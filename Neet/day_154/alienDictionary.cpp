




class Solution 
{
    public:
    string alienOrder(vector<string>& words) 
    {
        if (words.empty() || !buildGraph(words)) return "";

        // FULL-dfs finding topo sort
        for (auto& [node, _] : graph) {
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

    bool buildGraph(vector<string>& words)
    {
        if (words.empty()) return false;
        int n = words.size();

        for (int i=1; i<n; i++) {
            string word1 = words[i-1];
            string word2 = words[i];
            int minLen = min(word1.length(), word2.length());

            // invalid case:
            if (word1.length() > word2.length() 
            && word1.substr(0, minLen) == word2.substr(0, minLen)) return false;

            for (int j=0; j<minLen; j++) {
                if (word1[j] != word2[j]) {
                    // an effective edge
                    graph[word1[j]].push_back(word2[j]);
                    // others are irrelevant
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