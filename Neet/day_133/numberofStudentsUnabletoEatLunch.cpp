



// students = [1,1,1,0,0,1]
// sandwiches = [1,0,0,0,1,1]
// Time: O(N)
// Space: O(N)
class Solution 
{
    public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        if (students.empty() || sandwiches.empty()) return 0;
        int n = students.size();
        
        stack<int> sandwicheStack;
        queue<int> studentQueue;

        for (int i=0; i<n; i++) {
            sandwicheStack.push(sandwiches[n-i-1]);
            studentQueue.push(students[i]);
        }

        int numOfConsecutiveUnmatchTimes = 0;
        while (!studentQueue.empty() && numOfConsecutiveUnmatchTimes < studentQueue.size()) {
            // if it is match
            if (!studentQueue.empty() && studentQueue.front() == sandwicheStack.top()) {
                sandwicheStack.pop();
                studentQueue.pop();
                numOfConsecutiveUnmatchTimes = 0; //when match, reset
            } else {
                // let the front student go the back
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                numOfConsecutiveUnmatchTimes++;
            }
        }
        return studentQueue.size();
    }
};