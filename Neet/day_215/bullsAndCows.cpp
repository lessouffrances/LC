class Solution 
{
    public:
    string getHint(string secret, string guess) 
    {
        if (secret.size() != guess.size()) return "";
        vector<int> secretCounter(10, 0);
        vector<int> guessCounter(10, 0);
        int n = secret.size();

        for (int i=0; i<n; i++) {
            secretCounter[secret[i]-'0']++;
            guessCounter[guess[i]-'0']++;
        }

        int bulls = 0, cows = 0;
        for (int i=0; i<n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                secretCounter[secret[i]-'0']--;
                guessCounter[guess[i]-'0']--;
            }
        }

        for (int i=0; i<10; i++) {
            cows += min(secretCounter[i], guessCounter[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};