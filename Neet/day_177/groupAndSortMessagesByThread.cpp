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
            if (timeStamp.empty()) return {};
            int n = timeStamp.size();
            if (replyTo.size() != n || messageText.size() != n) return {};

            vector<bool> isRoot(n, false);
            // the pairs are auto sorted based on timestamp
            set<pair<int, int>> rootsWithIdx; // { time, rootIdx }

            // find the roots first and sort with timestamp
            for (int i=0; i<n; i++) {
                if (replyTo[i] == -1) {
                    isRoot[i] = true;
                    rootsWithIdx.insert( {timeStamp[i], i} );
                }
            }

            // construct group
            unordered_map<int, vector<pair<int, string>>> groups; // {rootIdx, { {time, msg} }}
            for (int i=0; i<n; i++) {
                if (isRoot[i]) continue;
                groups[replyTo[i]].push_back( {timeStamp[i], messageText[i]} );
            }

            // sort the groups and populate res
            vector<vector<string>> res;
            for (auto& [ _, rootIdx] : rootsWithIdx) {
                vector<string> group;
                group.push_back(messageText[rootIdx]);

                sort(groups[rootIdx].begin(), groups[rootIdx].end());
                for (auto& [ _, msg] : groups[rootIdx]) {
                    group.push_back(msg);
                }
                res.push_back(group);
            }
            return res;
    }
};
