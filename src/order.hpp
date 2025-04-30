#pragma once
#include <string>
#include <utility>

/*
 * order.hpp
 * Author: Harvey Kyllonen
 * Date: 04/30/2025
 * Represents a trading order with various attributes.
 * Attributes:
 * - id: Internal order ID
 * - symbol: Asset symbol
 * - side: BUY or SELL
 * - type: MARKET or LIMIT
 * - quantity: Total quantity
 * - price: Limit price (ignored for market orders)
 * - tif: Time in force (Good-Til-Cancelled or Immediate-Or-Cancel)
 * - timestamp: Nanosecond or ms time (for price-time priority)
 * - OrderType: Enum for order type (LIMIT or MARKET)
 * - OrderSide: Enum for order side (BUY or SELL)
 * - TimeInForce: Enum for time in force (GTC or IOC)
 * - Order constructor: Initializes an order with the given parameters
 */

enum class OrderType : std::uint8_t { LIMIT, MARKET };  // LIMIT or MARKET
enum class OrderSide : std::uint8_t { BUY, SELL };  // BUY or SELL
enum class TimeInForce : std::uint8_t { GTC, IOC };  // Good-Til-Cancelled, Immediate-Or-Cancel

struct Order {
    int id;  // Internal order ID
    std::string symbol;  // Asset symbol
    OrderSide side;  // BUY or SELL
    OrderType type;  // MARKET or LIMIT
    int quantity;  // Total quantity
    double price;  // Limit price (ignored for market orders)
    TimeInForce tif;  // Time in force
    long timestamp;  // Nanosecond or ms time (for price-time priority)

    Order(int id, std::string symbol, OrderSide side, OrderType type, int quantity, double price, TimeInForce tif,
          long timestamp)
        : id(id)
        , symbol(std::move(symbol))
        , side(side)
        , type(type)
        , quantity(quantity)
        , price(price)
        , tif(tif)
        , timestamp(timestamp) {}
};  // Order
