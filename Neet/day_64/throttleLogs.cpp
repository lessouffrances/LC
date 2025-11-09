#include <vector>
#include <algorithm>
#include <cstdio>

struct Log final {
    unsigned int size;
    unsigned long timestamp;
};

unsigned long throttleLogs(unsigned int bytesLimit, unsigned int window, const std::vector<Log>& logs) 
{
    unsigned int currentTotal = 0;
    unsigned long overallTotal = 0;
    std::vector<Log> currentWindow;

    for (size_t i=0; i<logs.size(); i++) 
    {
        unsigned int currentTime = logs[i].timestamp;
        unsigned int currentSize = logs[i].size;

        // let earlier log roll out
        // find the right current window start
        unsigned int windowStart = (currentTime >= window) ? (currentTime-window) : 0;

        currentWindow.erase(
            std::remove_if(currentWindow.begin(), currentWindow.end(), [windowStart](const Log& log) {
                return log.timestamp < windowStart;
            }),
            currentWindow.end()
        );

        // compute currentTotal as the sum of all sizes in the currentWindow
        currentTotal = 0;
        for (const Log& log : currentWindow) {
            currentTotal += log.size;
        }


        if (currentTotal + currentSize <= bytesLimit) {
            currentWindow.push_back( {currentSize, currentTime} );
            overallTotal += currentSize;
        }
    }
    
    std::printf("%lu\n", overallTotal);
    return overallTotal;
}

int main() 
{
    unsigned int bytesLimit = 10;
    unsigned int window = 5;
    std::vector<Log> logs = { {2, 0}, {4, 3}, {5, 5}, {5, 7} };
    unsigned long result = throttleLogs(bytesLimit, window, logs);
}