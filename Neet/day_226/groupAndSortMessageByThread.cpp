// Group and Sort Messages by Thread
// You are given three arrays of length n:

// timeStamp[i] — the timestamp of the i-th message
// replyTo[i] — the index of the message that the i-th message is replying to, or -1 if it is a root message (i.e. starts a new thread)
// messageText[i] — the text content of the i-th message

// Group all messages into threads. A thread is defined by a root message (where replyTo[i] == -1), and all messages that directly reply to it.
// Return a 2D array of message texts where:

// Each inner array represents one thread, with the root message appearing first followed by its replies
// Threads are ordered by the timestamp of their root message in ascending order
// Replies within each thread are ordered by their timestamp in ascending order

// Example:
// Input:
// timeStamp   = [102, 104, 100, 103, 101]
// replyTo     = [-1, 0, -1, 2, 2]
// messageText = ["NewProjectUpdate", "GreatProgress", "MeetingAt3AM", "CanYouReschedule", "SoundsGood"]

// Output:
// [["MeetingAt3AM", "SoundsGood", "CanYouReschedule"],
//  ["NewProjectUpdate", "GreatProgress"]]
// Constraints:

// 1 <= n <= 10^5
// 0 <= timeStamp[i] <= 10^9
// replyTo[i] == -1 or 0 <= replyTo[i] < n
// All timestamps are unique
// A reply always points to a root message (no nested replies)

class Solution 
{
    public:
    // Input: timeStamp = [102, 104, 100, 103, 101], 
    // replyTo = [-1, 0, -1, 2, 2], 
    // messageText = ["NewProjectUpdate", "GreatProgress", "MeetingAt3AM", "CanYouReschedule", "SoundsGood"]
    // output: [ ["MeetingAt3AM", "SoundsGood", "CanYouReschedule"], ["NewProjectUpdate", "GreatProgress"] ]
    vector<vector<string>> groupMessages(vector<int>& timeStamp, 
        vector<int>& replyTo, vector<string>& messageText) {

            // group by thread
            unordered_map<int, vector<pair<int, string>>> pool;
            vector<pair<int, int>> tsToRootIdx;

            for (int i=0; i<messageText.size(); i++) {
                if (replyTo[i] == -1) {
                    tsToRootIdx.push_back( {timeStamp[i], i} );
                } else {
                    pool[replyTo[i]].push_back( {timeStamp[i], messageText[i]} );
                }
            }

            // root should be sorted by ts too
            sort(tsToRootIdx.begin(), tsToRootIdx.end());
        
            vector<vector<string>> res;
            for (auto& [_, rootIdx] : tsToRootIdx) {
                auto& tsMsg = pool[rootIdx];
                sort(tsMsg.begin(), tsMsg.end());

                vector<string> thread;
                thread.push_back(messageText[rootIdx]);
                for (auto& [_, msg] : tsMsg) {
                    thread.push_back(msg);
                }
                res.push_back(thread);
            }
            
            return res;
    }
};
