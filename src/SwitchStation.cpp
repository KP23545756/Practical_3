#include "SwitchStation.h"
#include "Notice.h"
#include <iostream>

SwitchStation::SwitchStation(std::string name, int capacity, bool startsPortable):EventUnit(name, capacity), isOpen(false), portableMode(startsPortable){}

void SwitchStation::open(){
    isOpen = true;
}

void SwitchStation::close(){
    isOpen = false;
}

void SwitchStation::reportStatus() const{
    std::string openStatus;
    if(isOpen){
        openStatus = "Open";
    }
    else{
        openStatus = "Closed";
    }
    std::string mode;
    if(portableMode){
        mode = "Portable/Battery";
    }
    else{
        mode = "Docked";
    }
    std::cout << name << " - " << openStatus<< ", Mode: " << mode << std::endl;
}

int SwitchStation::getCapacity() const{
    if(portableMode){
        return capacity - 1;
    } else{
        return capacity;
    }
}

void SwitchStation::update(const Notice& notice){
    if(notice.type == NoticeType::EVACUATE){
        close();
    }
}

void SwitchStation::dock(){
    portableMode = false;
}

void SwitchStation::undock(){
    portableMode = true;
}
