class Solution {
    public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        const int MOD = 1e9 + 7;

        queue<pair<int, long long>> delayDates; // { date, count }
        queue<pair<int, long long>> forgetDates;

        int day = 1;
        long long active = 0;
        long long totalKnowing = 1;

        delayDates.push( {day+delay, 1} );
        forgetDates.push( {day+forget, 1} );
        day++;

        while (day <= n) {
            // check how many people should forget today
            while (!forgetDates.empty() && forgetDates.front().first == day) {
                auto [date, count] = forgetDates.front();
                forgetDates.pop();

                active = (active - count + MOD) % MOD;
                totalKnowing = (totalKnowing - count + MOD) % MOD;
            } 

            // check how many people should become active today
            while (!delayDates.empty() && delayDates.front().first == day) {
                auto [date, count] = delayDates.front();
                delayDates.pop();

                active = (active + count + MOD) % MOD;
            } 

            // let active people share
            if (active > 0) {
                totalKnowing = (totalKnowing + active + MOD) % MOD;
                forgetDates.push( {day+forget, active} );
                delayDates.push( {day+delay, active} );
            }
            day++;
        }

        return totalKnowing;
    }
};