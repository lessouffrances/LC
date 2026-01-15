class Solution 
{
    public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        // build bankHash
        for (int i=0; i<bank.size(); i++) {
            bankHash[i] = buildHash(bank[i]);
        }

        return bfs(startGene, endGene, bank);
    }
    private:
    map<int, unordered_map<int, char>> bankHash;
    int bfs(string startGene, string endGene, vector<string>& bank)
    {
        queue<string> q;
        q.push(startGene);
        set<string> visited;
        visited.insert(startGene);

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto gene = q.front();
                q.pop();
                if (gene == endGene) {
                    return level;
                }
                
                unordered_map<int, char> geneHash = buildHash(gene);
                for (int j=0; j<bankHash.size(); j++) {
                    string validMutation = bank[j];
                    unordered_map<int, char> validGeneHash = bankHash[j];
                
                    // verify if the mutation is valid
                    int diffNum = 0;
                    bool isValid = true;
                    for (auto& [idx, ch] : geneHash) {
                        if (ch != validGeneHash[idx]) {
                            diffNum++;
                        }
                        if (diffNum > 1) {
                            isValid = false;
                            break;
                        }
                    }
                    if (isValid && diffNum == 1 && !visited.count(validMutation)) {
                        visited.insert(validMutation);
                        q.push(validMutation);
                    }
                }
            }
            level++;
        }
        return -1;
    }

    unordered_map<int, char> buildHash(const string& s)
    {
        unordered_map<int, char> map;
        for (int i=0; i<s.size(); i++) {
            map[i] = s[i];
        }
        return map;
    }
};