class MagicDictionary 
{
    public:
    MagicDictionary() {}
        
    void buildDict(vector<string> dictionary) {
        for (auto& str : dictionary) {
            dictHash.push_back(buildHash(str));
        }
    }
        
    bool search(string searchWord) {
        unordered_map<int, char> searchWordHash = buildHash(searchWord);

        for (auto& hash : dictHash) {
            if (differByOne(searchWordHash, hash)) return true;
        }
        return false;
    }

    private:
    vector<unordered_map<int, char>> dictHash;
    unordered_map<int, char> buildHash(const string& s) 
    {
        unordered_map<int, char> res;
        for (int idx=0; idx<s.length(); idx++) {
            res[idx] = s[idx];
        }
        return res;
    }

    bool differByOne(unordered_map<int, char>& s, unordered_map<int, char>& t) {
        if (s.size() != t.size()) return false;
        int diff = 0;
        for (auto& [idx, ch] : s) {
            if (ch != t[idx]) {
                diff++;
            }
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }
};
    
    