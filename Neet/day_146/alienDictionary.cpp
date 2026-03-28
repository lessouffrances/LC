// The rule is: compare every adjacent pair of words (words[i], words[i+1]), 
// scan character by character until you find the first differing character 
// — that gives you one directed edge w1[j] → w2[j], 
// meaning w1[j] comes before w2[j] in the alien alphabet.

// Time: O(N * M), where N is the number of words, and M is the avg size of each word
// Space: O(U + E), where U is the number of unique chars, E is the number of edges.

class Solution 
{
    public:
    string alienOrder(vector<string>& words) 
    {
        if (words.empty()) return "";
        if (!buildGraph(words)) return "";

        // if build graph success
        // do FULL-DFS to find the topo sort
        for (auto& [node, _] : graph) {
            if (visited.count(node)) continue;
            if (dfsDetectCycle(node)) return "";
        }

        reverse(finishingOrder.begin(), finishingOrder.end());
        return finishingOrder;
    }
    private:
    unordered_map<char, vector<char>> graph;
    unordered_set<int> ancestorStack;
    unordered_set<int> visited;
    string finishingOrder;

    bool dfsDetectCycle(int u)
    {
        ancestorStack.insert(u);
        visited.insert(u);

        for (int v : graph[u]) {
            if (ancestorStack.count(v)) return true;
            if (visited.count(v)) continue;
            if (dfsDetectCycle(v)) return true;
        }

        finishingOrder.push_back(u);
        ancestorStack.erase(u);
        return false;
    }

    bool buildGraph(vector<string>& words)
    {
        if (words.empty()) return false;
        int n = words.size();

        // each char in all words is a node
        for (auto& w : words) {
            for (char node : w) {
                graph[node] = {};
            }
        }

        // for each adj pair of words
        for (int i=0; i<n-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            int minLen = min(word1.length(), word2.length());

            // invalid case:
            if (word1.length() > word2.length() 
            && word1.substr(0, minLen) == word2.substr(0, minLen)) return false;

            // otherwise valid:
            // only see the first differing char
            for (int j=0; j<minLen; j++) {
                if (word1[j] != word2[j]) {
                    graph[word1[j]].push_back(word2[j]);
                    // others are irrelavant
                    break;
                }
            }
        }
        return true;
    }
};