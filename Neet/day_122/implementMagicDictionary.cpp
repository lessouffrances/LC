class MagicDictionary 
{
    public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) 
    {
        dict = dictionary;
    }
    bool search(string searchWord) 
    {
        for (auto& word : dict) {
            if (word.length() == searchWord.length()) {
                if (dfs(0, searchWord, word, 0)) return true;
            }   
        }
        return false;
    }
    private:
    vector<string> dict;

    bool dfs(int currIdx, const string& searchWord, const string& word, int diffCount)
    {
        if (currIdx == searchWord.size()) {
            return currIdx == word.size() && diffCount == 1;
        }

        if (searchWord[currIdx] == word[currIdx]) {
            return dfs(currIdx+1, searchWord, word, diffCount);
        } else {
            return dfs(currIdx+1, searchWord, word, diffCount+1);
        }
    }
};
    
   