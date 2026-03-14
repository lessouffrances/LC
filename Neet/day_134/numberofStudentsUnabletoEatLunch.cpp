class Solution 
{
    public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        if (students.empty() || sandwiches.empty()) return 0;

        int n = students.size();
        queue<int> studentQueue;
        stack<int> sandwicheStack;

        for (int i=0; i<n; i++) {
            sandwicheStack.push( sandwiches[n-i-1] );
            studentQueue.push( students[i] );
        }

        int uneffectiveTimes = 0;
        while (!studentQueue.empty() && uneffectiveTimes < studentQueue.size()) {
            // not a match, student go to back
            if (studentQueue.front() != sandwicheStack.top()) {
                uneffectiveTimes++;
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
            } else {
                uneffectiveTimes = 0;
                studentQueue.pop();
                sandwicheStack.pop();
            }
        }
        return studentQueue.size();
    }
};