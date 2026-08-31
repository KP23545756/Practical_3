#ifndef MERCHVENDOR_H
#define MERCHVENDOR_H
#include "EventUnit.h"
struct Notice;
/**
 * @brief Concrete Leaf: a merchandise vendor.
 *
 * getCapacity() represents remaining stock, not headcount 
 */
class MerchVendor:public EventUnit{
private:
    bool isOpen;
    int stockLevel;
public:
    /**
     * @brief Construct a merch vendor.
     * @param name Display name.
     * @param capacity amount of customers allowed in store etc.
     * @param stock Starting stock level.
     */
    MerchVendor(std::string name, int capacity, int stock = 100);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
    /**
     * @brief Sell some stock.
     * @param quantity Amount to remove. Never drops stock below zero.
     */
    void sell(int quantity);
    /**
     * @brief Restock.
     * @param quantity Amount to add.
     */
    void restock(int quantity);
};


#endif // MERCHVENDOR_H
