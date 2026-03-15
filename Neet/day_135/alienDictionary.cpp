// The rule is: compare every adjacent pair of words (words[i], words[i+1]), 
// scan character by character until you find the first differing character 
// — that gives you one directed edge w1[j] → w2[j], 
// meaning w1[j] comes before w2[j] in the alien alphabet.

// Time: O(V)
// Space: O(V+E)
class Solution 
{
    public:
    string alienOrder(vector<string>& words) 
    {
        if (words.empty()) return "";
        if (!buildGraph(words)) return "";

        // if build graph successfully
        // do FULL-DFS to find the topo ordering
        for (auto& [u, adjList] : graph) {
            if (visited.count(u)) continue;
            if (dfsDetectCycle(u)) return "";
        }

        reverse(finishingOrder.begin(), finishingOrder.end());
        return string(finishingOrder.begin(), finishingOrder.end());
    }
    private:
    unordered_map<char, vector<char>> graph;
    unordered_set<char> visited;
    unordered_set<char> ancestorStack;
    vector<char> finishingOrder;

    bool dfsDetectCycle(char u)
    {
        visited.insert(u);
        ancestorStack.insert(u);

        for (char v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            if (dfsDetectCycle(v)) return true;
        }

        ancestorStack.erase(u);
        finishingOrder.push_back(u);
        return false;
    }

    bool buildGraph(vector<string>& words)
    {
        if (words.empty()) return false;
        int n = words.size();

        // each char in all the words is a node
        for (const auto& w : words) {
            for (char ch : w) {
                graph[ch] = {};
            }
        }

        // for each adj pair of words
        for (int i=0; i<n-1; i++) {
            string w1 = words[i], w2 = words[i+1];
            int minLen = min(w1.length(), w2.length());

            // invalid case
            if (w1.length() > w2.length() 
            && w1.substr(0, minLen) == w2.substr(0, minLen)) return false;

            // only see the first differing char
            for (int j=0; j<minLen; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }
        return true;
    }
};