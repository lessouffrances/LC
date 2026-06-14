class Solution 
{
    public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        if (people.empty()) return 0;
        int n = people.size();

        // sort in reverse order
        sort(people.begin(), people.end());
        int numOfBoats = 0;
        int left = 0, right = n-1;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                // the heaviest person can be paired with the lightest person
                left++;
                right--;
                numOfBoats++;
            } else {
                right--;
                numOfBoats++;
            }
        }
        return numOfBoats;
    }
};