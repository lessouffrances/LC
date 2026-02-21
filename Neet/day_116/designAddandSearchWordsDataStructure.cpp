class WordDictionary 
{
    public:
    WordDictionary() {}
    void addWord(string word) 
    {
        wordSet.insert(word);
    }

    bool search(string word) 
    {
        for (auto& w : wordSet)
            if (isSubstrMatch(w, word)) return true;
        return false;
    }
    
    private:
    set<string> wordSet;
    bool isSubstrMatch(const string& s, const string& t) 
    {
        if (s.length() != t.length()) return false;
        for (int i = 0; i < (int)t.size(); i++)
            if (s[i] != t[i] && t[i] != '.' && s[i] != '.') return false;
        return true;
    }
};