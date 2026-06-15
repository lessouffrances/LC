class Solution 
{
    public:
    string getHint(string secret, string guess) 
    {
        // bulls are 100% correct, idx and val
        // cows are in there but wrong pos
        if (secret.length() != guess.length()) return "";
        int n = secret.length();
        // build a freq for secret
        unordered_map<char, int> secretFreq;
        for (char ch : secret) {
            secretFreq[ch]++;
        }

        // first step: find the bulls first
        int bulls = 0;
        unordered_set<int> bullIdxes;
        for (int i=0; i<n; i++) {
            if (secret[i] == guess[i]) {
                bullIdxes.insert(i);
                bulls++;
                secretFreq[secret[i]]--;
                if (secretFreq[secret[i]] == 0) {
                    secretFreq.erase(secret[i]);
                }
            }
        }

        int cows = 0;
        for (int i=0; i<n; i++) {
            if (bullIdxes.count(i)) continue;
            if (secretFreq.count(guess[i])) {
                cows++;
                secretFreq[guess[i]]--;
                if (secretFreq[guess[i]] == 0) {
                    secretFreq.erase(guess[i]);
                }
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};