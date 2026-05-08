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
        vector<int>& replyTo,vector<string>& messageText) {
            if (timeStamp.empty() || replyTo.empty() || messageText.empty()) return {};
            int n = timeStamp.size();
            if (replyTo.size() != n || messageText.size() != n) return {};

            // init with false
            vector<bool> isRoot(n, false);

            set<pair<int, int>> roots; // { time, rootIdx }
            for (int i=0; i<n; i++) {
                if (replyTo[i] == -1) {
                    isRoot[i] = true;
                    roots.insert( {timeStamp[i], i } );
                }
            }
            // roots are identified and already sorted in ascending order by time

            unordered_map<int, vector<pair<int, string>>> collector;
            for (int i=0; i<n; i++) {
                if (isRoot[i] == true) continue;
                collector[replyTo[i]].push_back( {timeStamp[i], messageText[i]} );
            }

            // sort the values
            for (auto& [ _, msgs] : collector) {
                sort(msgs.begin(), msgs.end());
            }

            // populate the res
            vector<vector<string>> res;
            for (auto& [ _, rootIdx] : roots) {
                vector<string> currGroup;
                currGroup.push_back(messageText[rootIdx]);
                for (auto& [ _, childMsg] : collector[rootIdx]) {
                    currGroup.push_back(childMsg);
                }
                res.push_back(currGroup);
            }

            return res;
    }
};
