class Solution 
{
    public:
    // The system emits an alert if any worker uses the key-card three 
    // or more times in a one-hour period.
    // keyTime: "HH:MM"
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) 
    {
        if (keyName.empty() || keyTime.empty()) return {};
        if (keyName.size() != keyTime.size()) return {};
        int n = keyName.size();

        for (int i=0; i<n; i++) {
            string name = keyName[i];
            string time = keyTime[i];
            recorder(name, time);
        }

        unordered_set<string> nameSet;
        for (auto& [name, accessRecord] : accessPerPeriod) {
            sort(accessRecord.begin(), accessRecord.end());
            for (int i=2; i<accessRecord.size(); i++) {
                if (accessRecord[i]-accessRecord[i-2] <= 60) {
                    nameSet.insert(name);
                }
            }
        }
        vector<string> res = vector<string>(nameSet.begin(), nameSet.end());
        sort(res.begin(), res.end());
        return res;
    }

    private:
    unordered_map<string, vector<int>> accessPerPeriod;

    void recorder(const string& name, const string& time) 
    {
        // process time
        string token;
        stringstream ss(time);
        getline(ss, token, ':');
        int hour = stoi(token); 
        getline(ss, token, ':');
        int minute = stoi(token);
        int timestamp = hour * 60 + minute;

        accessPerPeriod[name].push_back(timestamp);
    }
};