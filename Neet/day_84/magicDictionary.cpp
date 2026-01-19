class MagicDictionary {
    public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) 
    {
        dict = dictionary;
        for (auto& word : dictionary) {
            hash[word] = buildHash(word);
        }
    }
    
    bool search(string searchWord) 
    {
        unordered_map<int, char> searchWordHash = buildHash(searchWord);
        for (auto& [dictWord, dictWordHash] : hash) {
            if (differByOne(searchWordHash, dictWordHash)) {
                return true;
            }
        }
        return false;
    }
    private:
    vector<string> dict;
    unordered_map<string, unordered_map<int, char>> hash;
    unordered_map<int, char> buildHash(const string& s) 
    {
        unordered_map<int, char> res;
        int i = 0;
        for (char ch : s) {
            res[i] = ch;
            i++;
        }
        return res;
    }

    bool differByOne(unordered_map<int, char>& s, unordered_map<int, char>& t)
    {
        if (s.size() != t.size()) return false;

        int diffNum = 0;
        for (auto& [idx, ch] : t) {
            if (s[idx] != ch) {
                diffNum++;
            }
            if (diffNum > 1) {
                return false;
            }
        }
        return diffNum == 1;
    }
};
    
/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */