#ifndef FOODVENDOR_H
#define FOODVENDOR_H
#include <string>
#include "EventUnit.h"
class FoodVendor: public EventUnit{
    private:
        bool isOpen;
        bool midOrder;
    public:
        FoodVendor(std::string name, int capacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        void update(const Notice&) override;
        void begineOrder();
        void finishOrder();
};

#endif // FOODVENDOR_H
