class Solution 
{
    public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        if (courses.empty()) return 0;
        int n = courses.size();

        // sort the courses by lastDay
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        // iteration thru the courses and always drop the longest course when exceeds the deadline
        priority_queue<int> pq; // maxHeap default
        int time = 0;
        for (int i=0; i<n; i++) {
            int duration = courses[i][0];
            int lastDay = courses[i][1];
            time += duration;
            pq.push(duration);

            if (time > lastDay) {
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};