#ifndef MERCHVENDOR_H
#define MERCHVENDOR_H
#include <string>
#include "EventUnit.h"
struct Notice;

class MerchVendor:public EventUnit{
    private:
        bool isOpen;
        int stockLevel;
    public:
        MerchVendor(std::string name, int capacity, int stock);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        void update(const Notice&) override;
        void sell(int quantity);
        void restock(int quantity);
};

#endif // MERCHVENDOR_H
