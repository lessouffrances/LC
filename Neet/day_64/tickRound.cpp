#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <tuple>

struct Tick final 
{
    double lowerBound;
    double upperBound;
    double width;
};

struct VariableTickTable final 
{
    double cabinetPrice;
    std::vector<Tick> tickRanges;
};

// helper to locate the corresponding tickable Width and lowerBound
std::tuple<double, double> getCorrespondingTickableWidth(double price, std::vector<Tick>& tickRanges)
{
    for (size_t i=0; i<tickRanges.size(); i++) {
        // range found
        if (price >= tickRanges[i].lowerBound && price < tickRanges[i].upperBound) {
            return std::make_tuple(tickRanges[i].width, tickRanges[i].lowerBound);
        }
    }
    // not tickable 
    return std::make_tuple(-1.0, -1.0);
}


std::vector<double> tickRound(const std::vector<double>& prices, const VariableTickTable &tickTable) 
{
    // sort the tickRanged based on the lowerBounds
    std::vector<Tick> mutableTickRanges = tickTable.tickRanges;

    std::sort(mutableTickRanges.begin(), mutableTickRanges.end(), 
        [](const Tick& a, const Tick& b) {
        return a.lowerBound < b.lowerBound;
    });
    
    std::vector<double> res;
    for (size_t i=0; i<prices.size(); i++) 
    {
        // if price less than or equal to cabinetPrice
        if (prices[i] <= tickTable.cabinetPrice) {
            res.push_back(tickTable.cabinetPrice);
            continue;
        } 
    
        double tickableWidth = std::get<0>(getCorrespondingTickableWidth(prices[i], mutableTickRanges));
        double tickableLowerBound = std::get<1>(getCorrespondingTickableWidth(prices[i], mutableTickRanges));
        double tickedPortion = prices[i] - tickableLowerBound;

        const double EPSILON = 1e-9;
        double remainder = std::fmod(tickedPortion, tickableWidth);

        // check if already on a tick
        if (remainder < EPSILON || std::abs(remainder-tickableWidth) < EPSILON) {
            res.push_back(prices[i]);
            continue;
        }
        
        double tickedPrice = tickableLowerBound + ((int)(tickedPortion / tickableWidth)+1) * tickableWidth;

        res.push_back(tickedPrice);
    }
    
    for (size_t i=0; i<res.size(); i++) {
        printf("%f\n", res[i]);
    }

    return res;
}

int main() 
{
    double cabinetPrice = 2.0;
    std::vector<Tick> tickRanges = { {2.0, 3.0, 0.01} , {3.0, 10.0, 0.05}, {10.0, INFINITY, 1.0} };
    VariableTickTable tickTable = { cabinetPrice, tickRanges };
    std::vector<double> prices = { 1.0, 2.25, 3.27, 15.8 };

    std::vector<double> result = tickRound(prices, tickTable);
    return 0;
}