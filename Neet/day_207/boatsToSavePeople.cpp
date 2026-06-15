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
            if (people[right]+people[left] <= limit) {
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