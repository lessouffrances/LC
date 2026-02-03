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
            if (searchWord.length() != word.length()) continue;

            int diffCount = 0;
            int n = searchWord.length();

            for (int i=0; i<n; i++) {
                if (searchWord[i] != word[i]) diffCount++;
                if (diffCount > 1) {
                    break;
                }
            }
            if (diffCount == 1) return true;
        }
        
        return false;
    }
    private:
    vector<string> dict;
};
    
