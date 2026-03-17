

// Time: O(M + N)
// Space: O(M + N)
class Solution 
{
    public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        if (ransomNote.length() > magazine.length()) return false;

        vector<int> ransomNoteCounter(26, 0);
        vector<int> magazineCounter(26, 0);

        for (int i=0; i<ransomNote.size(); i++) {
            ransomNoteCounter[ransomNote[i]-'a']++; 
        }
        for (int i=0; i<magazine.size(); i++) {
            magazineCounter[magazine[i]-'a']++;
        }
        for (int i=0; i<ransomNoteCounter.size(); i++) {
            if (magazineCounter[i] < ransomNoteCounter[i]) {
                return false;
            } 
        }
        return true;
    }
};