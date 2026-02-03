







class AutocompleteSystem 
{
    public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    {
        currPrefix = "";

        // build freq
        int n = sentences.size();
        for (int i=0; i<n; i++) {
            freq[sentences[i]] = times[i];
        }
    }
    vector<string> input(char c) 
    {
        // if #, save result and reset
        if (c == '#') {
            freq[currPrefix]++;
            currPrefix = "";
            return {};
        }

        currPrefix += c;
        // find the match in freq
        for (auto& [sentence : count] : freq) {
            if (sentence.find(currPrefix) == 0) {
                pq.push( {count, sentence} );
            }
        }

        // pop the top 3
        vector<string> res;
        for (int i=0; i<3; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    } 
    
    private:
    struct Comp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            } 
            return a.second > b.second;
        }
    };
    string currPrefix; 
    unordered_map<string, int> freq;
    priority_queue<pair<int, string>, vector<int, string>, Comp> freqToSentences;
};
    
   