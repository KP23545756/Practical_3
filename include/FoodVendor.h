#ifndef FOODVENDOR_H
#define FOODVENDOR_H
#include "EventUnit.h"
struct Notice;
/**
 * @brief Concrete Leaf: a food vendor.
 *
 * Outdoor unit - a weather alert closes it, unlike indoor leaves
 * which ignore weather entirely. Finishes the current order before
 * fully stopping service.
 */
class FoodVendor:public EventUnit{
private:
    bool isOpen;
    bool midOrder;
public:
    /**
     * @brief Construct a food vendor.
     * @param name Display name.
     * @param capacity Queue capacity.
     */
    FoodVendor(std::string name, int capacity);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
    /**
     * @brief Mark that an order is now being prepared.
     */
    void beginOrder();
    /**
     * @brief Mark that the in-progress order was completed normally.
     */
    void finishOrder();
};
#endif // FOODVENDOR_H
