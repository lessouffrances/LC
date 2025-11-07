#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

struct Quote final 
{
    unsigned int bidPrice;
    unsigned int bidQuantity;
    unsigned int offerPrice;
    unsigned int offerQuantity;
};

struct Order final 
{
    unsigned long timestamp;
    unsigned long orderID;
    unsigned int price;
    unsigned int quantity;
    bool isBid;
};

struct Cancel final 
{
    unsigned long orderID;
    unsigned long timestamp;
};

Quote displayLimitOrders(unsigned long lotSize, const std::vector<Order>& orders, const std::vector<Cancel>& cancels) 
{
    // define a new struct to encapsulate all events: Orders and Cancels
    struct Event 
    {
        unsigned long orderID;
        bool isCancel;
        unsigned long timestamp;
    };

    std::vector<Event> events;
    // encapsulate bids, offers, and cancels in type Event
    for (size_t i=0; i<orders.size(); i++) 
    {
        events.push_back( {orders[i].orderID, false, orders[i].timestamp} );
    }
    for (size_t i=0; i<cancels.size(); i++) 
    {
        events.push_back( {cancels[i].orderID, true, cancels[i].timestamp} );
    }

    // sort all events in the ascending order of time
    std::sort(events.begin(), events.end(),[](const Event& a, const Event &b) {
        return a.timestamp < b.timestamp;
    });

    // update the current lot
    if (lotSize <= events.size()) 
    {
        events.erase(events.begin(), events.end()-lotSize);
    } 

    std::map<unsigned int, unsigned int> bids;
    std::map<unsigned int, unsigned int> offers;

    for (size_t i=0; i<events.size(); i++) 
    {
        if (!events[i].isCancel) {
            // use the orderID to find the associated order
            auto it = std::find_if(orders.begin(), orders.end(), [orderID = events[i].orderID](const Order& order) {
                return order.orderID == orderID;
            });
            
            if (it->isBid) {
                bids[it->price] += it->quantity;
            } else {
                offers[it->price] += it->quantity;
            }
        } else {
            // use the orderID to find the associated order
            auto it = std::find_if(orders.begin(), orders.end(), [orderID = events[i].orderID](const Order& order) {
                return order.orderID == orderID;
            });

            if (it->isBid) {
                bids[it->price] -= it->quantity;
                if (bids[it->price] <= 0) {
                    bids.erase(it->price);
                }
            } else {
                offers[it->price] -= it->quantity;
                if (offers[it->price] <= 0) {
                    offers.erase(it->price);
                }
            }
        }
    }

    for (const auto& pair : bids) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    for (const auto& pair : offers) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    Quote res = {0, 0, 0, 0};

    if (!bids.empty()) {
        auto bestBid = bids.rbegin();  
        res.bidPrice = bestBid->first;
        res.bidQuantity = bestBid->second;
    }

    if (!offers.empty()) {
        auto bestOffer = offers.begin();
        res.offerPrice = bestOffer->first;
        res.offerQuantity = bestOffer->second;
    }

    return res;
}


int main() 
{
    unsigned long lotSize = 10;
    unsigned int numOfActions = 5;
    std::vector<Order> orders = {{0, 1, 10, 50, true}, {1, 2, 12, 80, true}, {2, 3, 11, 150, true}, {3, 4, 11, 20, true}};
    std::vector<Cancel> cancels = {{2, 4}};

    Quote result = displayLimitOrders(lotSize, orders, cancels);
    std::cout << "The quote is: " << result.bidPrice << " " << result.bidQuantity << " " << result.offerPrice <<  " " << result.offerQuantity << " " << std::endl;
    return 0;
}