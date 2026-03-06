

// Time: O (26 * M * N) where N = number of words, M = length of each word
// Space: wordSet stores O (M * N)
//        visited stores O (M * N)
//        queue can stores O (M * N) at a time

class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        // edge case 1: if already be solved
        if (beginWord == endWord) return 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // edge case 2: if the options do not include endWord
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);

        int steps = 1;
        while (!q.empty()) {

            // process all the word in the current q because 
            // they all need to take 1 more steps forward
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto word = q.front();
                q.pop();

                if (word == endWord) return steps;
                // change each char in this word
                // and see if the newWord is in the set
                for (int i=0; i<word.length(); i++) { // loop thru word length
                    char originalWord = word[i];

                    for (char newCh='a'; newCh<='z'; newCh++) {  // loop thru 26
                        word[i] = newCh;
                        if (!wordSet.count(word)|| visited.count(word)) {
                            word[i] = originalWord; // backtrack
                            continue;
                        }
                        q.push(word);
                        visited.insert(word);
                        word[i] = originalWord; // backtrack
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};