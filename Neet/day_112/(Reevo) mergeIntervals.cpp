


class Solution 
{
    public:
    string earliestCommonAvailableTime(vector<string>& events, int k)
    {
        if (events.empty()) return "-1";
        int n = events.size();

        vector<vector<double>> intervals;
        for (int i=0; i<n; i++) {
            Event e = parseEvent(events[i]);
            intervals.push_back( {e.startTime, e.endTime} );
        }

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        double kInHours = k / 60.0;
        // check if there's time before the first interval from 0.0;
        double firstStartTime = intervals[0][0];
        if (firstStartTime > 0.0) {
            double before = firstStartTime - 0.0;
            if (before >=  kInHours) return "00:00";
        }

        // when there is no overlap, check if the interval is >= kInHours
        double prevEndTime = intervals[0][1];
        for (int i=1; i<n; i++) {
            double currStartTime = intervals[i][0];
            double currEndTime = intervals[i][1];

            if (currStartTime > prevEndTime) {
                double empty = currStartTime - prevEndTime;
                if (empty >= kInHours) return doubleToTime(prevEndTime);
            }
            prevEndTime = max(prevEndTime, currEndTime);
        }

        // check if there's time after the last interval
        double lastEndTime = intervals.back()[1];
        if (lastEndTime < 24.0) {
            double after = 24.0 - lastEndTime;
            if (after >= kInHours) return doubleToTime(lastEndTime);
        }

        return "-1";
    }
    private:
    struct Event
    {
        string name;
        string action;
        double startTime;
        double endTime;
    };

    Event parseEvent(const string& event)
    {
        Event res;
        string token;

        stringstream ss(event);
        getline(ss, res.name, ' ');
        getline(ss, res.action, ' ');
        getline(ss, token, ' ');
        res.startTime = timeToDouble(token);
        getline(ss, token, ' ');
        res.endTime = timeToDouble(token);

        return res;
    }

    string doubleToTime(double time)
    {
        int h = (int)time;
        int m = (int)((time - h) * 60 + 0.5);  // +0.5 for rounding
        
        if (m >= 60) {
            h++;
            m = 0;
        }
        string hStr = (h < 10 ? "0" : "") + to_string(h);
        string mStr = (m < 10 ? "0" : "") + to_string(m);
        return hStr + ":" + mStr;
    }
    double timeToDouble(const string& time)
    {
        if (time.length() != 5 || time[2] != ':') return -1.0;

        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2)); // string ends has extra chars, so dictate the size
        return hours + minutes/60.0;
    }
};