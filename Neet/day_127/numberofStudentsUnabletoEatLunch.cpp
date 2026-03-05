class Solution 
{
    public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int n = students.size();

        queue<int> studentQueue;
        stack<int> sandwichStack;

        for (int i=0; i<n; i++) {
            sandwichStack.push(sandwiches[n-i-1]);
            studentQueue.push(students[i]);
        }    

        int lastServed = 0;
        while (!studentQueue.empty() && lastServed < (int)studentQueue.size()) {
            // is a match
            if (sandwichStack.top() == studentQueue.front()) {
                sandwichStack.pop();
                studentQueue.pop();
                lastServed = 0;
            } else {
                // not a match, student go to the back of the queue
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                lastServed++;
            }
        }
        return studentQueue.size();
    }
};