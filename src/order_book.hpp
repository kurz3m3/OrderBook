#pragma once

#include <map>
#include <mutex>
#include <queue>
#include <string>

#include "order.hpp"

class OrderBook {
public:
    explicit OrderBook(const std::string &symbol);

    void add_order(const Order &order);
    void match();  // try to match orders


private:
    std::string symbol;

    // Buy orders: Highest price first
    std::map<double, std::queue<Order>, std::greater<>> buy_orders;

    // Sell orders: Lowest price first
    std::map<double, std::queue<Order>, std::less<>> sell_orders;

    std::mutex book_mutex;  // Mutex for thread safety
};
