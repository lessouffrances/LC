
// the strategy is either can accomodate the lightest person with the heaviest person
// or just the heaviest person

class Solution 
{
    public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        if (people.empty()) return 0;
        int n = people.size();
        sort(people.begin(), people.end());

        int left = 0, right = n-1;
        int numOfBoats = 0;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (people[left] + people[right] <= limit) {
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