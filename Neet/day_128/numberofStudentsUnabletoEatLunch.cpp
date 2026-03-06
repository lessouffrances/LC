


class Solution 
{
    public:
    // students =   [1,1,1,0,0,1]
    // sandwiches = [1,0,0,0,1,1]

    //   [1,1,0,0,1]
    //   [0,0,0,1,1]

    //   [1,0,0,1,1]
    //   [0,0,0,1,1]

    //   [0,0,1,1,1]
    //   [0,0,0,1,1]

    //    [0,1,1,1]
    //    [0,0,1,1]

    //    [1,1,1]   ? >= queue.size() should exit
    //    [0,1,1]

    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        if (students.empty() || sandwiches.empty()) return 0;

        int n = students.size();
        stack<int> sandwichesStack;
        queue<int> studentsQueue;

        for (int i=0; i<n; i++) {
            sandwichesStack.push(sandwiches[n-i-1]);
            studentsQueue.push(students[i]);
        }

        int numOfUnmatch = 0;
        while (!studentsQueue.empty() && numOfUnmatch < studentsQueue.size()) {
            // if is a match
            if (!studentsQueue.empty() && studentsQueue.front() == sandwichesStack.top()) {
                sandwichesStack.pop();
                studentsQueue.pop();
                numOfUnmatch = 0; // reset
            } else {
                // if not a match, the front student go to the back of the queue
                studentsQueue.push(studentsQueue.front());
                studentsQueue.pop();
                numOfUnmatch++;
            }
        }

        return studentsQueue.size();
    }
};