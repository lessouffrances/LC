class AutocompleteSystem 
{
    public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    {
        currInput = "";
        int n = sentences.size();
        for (int i=0; i<n; i++) {
            freq[sentences[i]] = times[i];
        }
    }
    vector<string> input(char c) 
    {
        if (c == '#') {
            freq[currInput]++;
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
        for (auto& [prefix, count] : freq) {
            if (prefix.find(currInput) == 0) {
                pq.push( {prefix, count} );
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
    unordered_map<string, int> freq;
    string currInput;
};
    
    