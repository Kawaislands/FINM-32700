#include <iostream>
#include <string>

class Order {
private:
    std::string order_id;
    bool is_bid;
    uint64_t quantity;
    double price;

public:
    // Constructor with initialization list
    Order(const std::string& order_id, bool is_bid, uint64_t quantity, double price)
            : order_id(order_id), is_bid(is_bid), quantity(quantity), price(price) {
        std::cout << "call constructor for " + order_id << std::endl;
    }

    // Copy constructor
    Order(const Order &other)
            : order_id(other.order_id), is_bid(other.is_bid), quantity(other.quantity), price(other.price) {
        std::cout << "call copy constructor for " + order_id << std::endl;
    }

    // Destructor
    ~Order() {
        std::cout << "call destructor for " + order_id << std::endl;
    }

    // Member function to get the price
    double get_price() const {
        return price;
    }

    // Stub functions for cancel and fill
    void cancel() {
        // Implementation for canceling the order
    }

    void fill(uint64_t qty) {
        // Implementation for filling the order
        if (qty < quantity) {
            quantity -= qty;
        } else {
            quantity = 0;
        }
    }
};

int main() {
    Order o1("order1", true, 123, 1.2);
    std::cout << o1.get_price() << std::endl;

    // Demonstrating dynamic allocation
    Order* o2 = new Order("order2", false, 100, 2.5);
    std::cout << o2->get_price() << std::endl;

    // Demonstrating copy constructor
    Order o3 = o1; // Or Order o3(o1);
    std::cout << "After copying, o3's price is: " << o3.get_price() << std::endl;

    // Cleanup
    delete o2; // Remember to delete dynamically allocated memory

    return 0;
}
