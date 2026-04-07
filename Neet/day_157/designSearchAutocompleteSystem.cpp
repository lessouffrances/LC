class AutocompleteSystem 
{
    public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    {
        currInput = "";
        for (int i=0; i<sentences.size(); i++) {
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
        auto comp = [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second < b.second; // higher freq on top
            } 
            return a.first > b.first; // smaller lexico on top
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq;

        for (auto& [sentence, count] : freq) {
            if (sentence.find(currInput) == 0) {
                pq.push( {sentence, count} );
            } 
        }

        int k = 3;
        vector<string> res;
        while (!pq.empty() && k>0) {
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
    private:
    string currInput;
    unordered_map<string, int> freq;
};