#include "MerchVendor.h"
#include "Notice.h"
#include <iostream>

MerchVendor::MerchVendor(std::string name, int capacity, int stock): EventUnit(name, capacity), isOpen(false), stockLevel(stock){}

void MerchVendor::open(){
    isOpen = true;
}

void MerchVendor::close(){
    isOpen = false;
}

void MerchVendor::reportStatus() const{
    std::cout << name << " - " <<(isOpen ? "Open" : "Closed")<< ", Stock: " << stockLevel << std::endl;
}

int MerchVendor::getCapacity() const{
    return stockLevel;
}
void MerchVendor::update(const Notice& notice){
    switch(notice.type){
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  " << name << " flagged for restock." << std::endl;
            break;
        case NoticeType::EVACUATE:
            close();
            break;
        case NoticeType::WEATHER_ALERT:
            close(); // outdoor unit
            break;
        default:
            break;
    }
}

void MerchVendor::sell(int quantity){
    stockLevel -= quantity;
    if(stockLevel < 0){
        stockLevel = 0;
    }
}

void MerchVendor::restock(int quantity){
    stockLevel += quantity;
}