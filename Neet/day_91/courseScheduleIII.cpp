class Solution 
{
    public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        if (courses.empty()) return 0;
        // earlier deadline first
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        priority_queue<int> pq; // store course lengths

        int currentTime = 0;
        for (auto& course : courses) {
            int length = course[0];
            int deadline = course[1];
            currentTime += length;
            pq.push(length);

            if (currentTime > deadline) {
                currentTime -= pq.top(); // drop the longest course and reset current time
                pq.pop(); 
            }
        }

        return pq.size();
    }
};