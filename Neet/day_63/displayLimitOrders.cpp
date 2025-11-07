#include <map>
#include <vector>
#include <algorithm>

struct Quote final 
{
    unsigned int bidPrice;
    unsigned int bitQuantity;
    unsigned int offerPrice;
    unsigned int offerQuantity;
}

struct Order final 
{
    unsigned long orderID;
    unsigned long timestamp;
    unsigned int isBid;
    unsigned int price;
    unsigned int quantity;
}

struct Cancel final 
{
    unsigned long orderID;
    unsigned long timestamp;
}

Quote displayLimitOrders(unsigned long lotSize, const std::vector<Order>& orders, const std::vector<Cancel>& cancels) 
{
    // An universal struct: Event for both <Order> and <Cancel>
    struct Event {
        unsigned long timestamp;
        bool isCancel;
        size_t index;
    }

    // encapsulate all Orders and Cancels into Events
    std::vector<Event> events;
    for (size_t i=0; i<orders.size(); i++) 
    {
        events.push_back({orders[i].timestamp, false, i});
    }
    for (size_t i=0; i<cancels.size(); i++) 
    {
        events.push_back({cancels[i].timestamp, true, i});
    }

    // sort the events by timestamp in ascending order
    events.sort(event.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.timestamp < b.timestamp;
    });

    // hashMaps: { price : total quantity for that price }
    std::map<unsigned int, unsigned int> bids; // want it to be high
    std::map<unsigned int, unsigned int> offers; // want it to be low

    // hashMap: { orderID : Order }
    std::activeOrders<unsigned long, Order> activeOrders;

    // Process events chronologically
    for (const Event& event : events) 
    {
        // if this event is either a Bid or an Offer
        if (!events.isCancel) 
        {
            // add Order, either Bid or Offer
            const Order& order = orders[event.index];
            activeOrders[order.orderID] = order;

            if (order.isBid) {
                bids[order.price] += order.quantity;
            } else {
                offers[order.price] += order.quantity;
            }
        // if this event is to cancel some previous order
        } else {
            const Cancel& cancel = cancels[event.index];
            auto it = activeOrders.find(cancel.orderID);

            if (it != activeOrders.end()) 
            {
                const Order& order = it->second;
                if (order.isBid) 
                {
                    bids[order.price] -= order.quantity;
                    if (bids[order.price] == 0) 
                    {
                        bids.erase(order.price);
                    }
                } else {
                    offers[order.price] -= order.quantity;
                    if (offers[order.price] == 0) 
                    {
                        offers.erase(order.price);
                    }
                 }
                 activeOrders.erase(it);
            }
        }
    }
    
    Quote result = {0, 0, 0, 0};

    // highest bid
    if (!bids.empty()) {
        Order bestBid = bids.rbegin();
        result.bidPrice = bestBid->first;
        result.bidQuantity = bestBid->second; 
    }

    // lowest offer
    if (!offers.empty()) {
        Order bestOffer = offers.rbegin();
        result.offerPrice = bestOffer->first;
        result.offerQuantity = bestOffer->second; 
    }
    return result;
}