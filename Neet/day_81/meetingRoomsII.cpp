class Solution 
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        // assign rooms to the early-started meetings
        sort(intervals.begin(), intervals.end());

        // earlier endtime on top of pq
        auto comp = [](const auto& a, const auto& b){
            return a[1] > b[1];  
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq{comp};

        int res = 0;
        for (int i=0; i<intervals.size(); i++) {
            if (!pq.empty()) {
                auto endTime = pq.top()[1];
                if (endTime <= intervals[i][0]) {
                    pq.pop();
                    res--;
                }
            }

            pq.push(intervals[i]);
            res++;
        }
        return res;
    }
};