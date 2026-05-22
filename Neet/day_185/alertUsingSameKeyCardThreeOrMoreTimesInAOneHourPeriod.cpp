class Solution 
{
    public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) 
    {
        if (keyName.empty() || keyTime.empty()) return {};
        if (keyName.size() != keyTime.size()) return {};

        int n = keyName.size();
        unordered_map<string, vector<int>> record;

        for (int i=0; i<n; i++) {
            record[keyName[i]].push_back(processTime(keyTime[i]));
        }

        unordered_set<string> nameSet;
        for (auto& [name, timestamps] : record) {
            sort(timestamps.begin(), timestamps.end());
            int m = timestamps.size();
            for (int j=2; j<m; j++) {
                if (timestamps[j]-timestamps[j-2] <= 60) {
                    nameSet.insert(name);
                }
            }
        }
        vector<string> res = vector<string>(nameSet.begin(), nameSet.end());
        sort(res.begin(), res.end());
        return res;
    }
    private:
    int processTime(const string time)
    {
        stringstream ss(time);
        string token;
        getline(ss, token, ':');
        int hours = stoi(token);
        getline(ss, token, ':');
        int minutes = stoi(token);

        return hours * 60 + minutes;
    }
};