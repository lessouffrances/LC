class AutocompleteSystem 
{
    public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    {
        currInput = "";
        int n = sentences.size();
        for (int i=0; i<n; i++) {
            freq[sentences[i]] = times[i];
            sentencesPool.insert(sentences[i]);
        }        
    }

    vector<string> input(char c) 
    {
        if (c == '#') {
            freq[currInput]++;
            sentencesPool.insert(currInput);
            currInput = "";
            return {};
        }

        currInput += c;
        auto comp = [](const auto& a, const auto& b){
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq{comp};

        for (auto& option : sentencesPool) {
            if (option.find(currInput) == 0) {
                int count = freq[option];
                pq.push( {option, count} );
            }
        }
        vector<string> res;
        int k = 3;
        while (!pq.empty() && k > 0) {
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        
        return res;
    }
    private:
    string currInput;
    unordered_map<string, int> freq;
    unordered_set<string> sentencesPool;
    
};
    
    