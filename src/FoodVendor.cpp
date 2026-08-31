#include "FoodVendor.h"
#include "Notice.h"
#include <iostream>

FoodVendor::FoodVendor(std::string name, int capacity):EventUnit(name, capacity), isOpen(false), midOrder(false){}

void FoodVendor::open(){
    isOpen = true;
}

void FoodVendor::close(){
    if(midOrder){
        std::cout << "  " << name << " finishing current order before closing" << std::endl;
        midOrder = false;
    }
    isOpen = false;
}

void FoodVendor::reportStatus() const{
    std::string openStatus;
    if(isOpen){
        openStatus = "Open";
    }
    else{
        openStatus = "Closed";
    }

    std::string orderNote;
    if(midOrder){
        orderNote = ", finishing an order";
    }
    else{
        orderNote = "";
    }

    std::cout << name << " - " << openStatus << orderNote << std::endl;
}

int FoodVendor::getCapacity() const{
    return capacity;
}

void FoodVendor::update(const Notice& notice){
    switch(notice.type){
        case NoticeType::WEATHER_ALERT:
            close(); // outdoor unit
            break;
        case NoticeType::EVACUATE:
            close();
            break;
        default:
            break;
    }
}

void FoodVendor::beginOrder(){
    midOrder = true;
}

void FoodVendor::finishOrder(){
    midOrder = false;
}
