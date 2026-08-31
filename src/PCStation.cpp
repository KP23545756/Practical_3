#include "PCStation.h"
#include "Notice.h"
#include <iostream>

PCStation::PCStation(std::string name, int capacity, std::string startingGame): EventUnit(name, capacity), isOpen(false),sessionsSuspended(false), currentGame(startingGame){}

void PCStation::open() {
    isOpen = true;
    sessionsSuspended = false;
    if(currentGame == "None"){
        currentGame = "Default Game";
    }
}

void PCStation::close() {
    isOpen = false;
    currentGame = "None";
}

void PCStation::reportStatus() const {
    std::string openStatus;
    if(isOpen){
        openStatus = "Open";
    }
    else{
        openStatus = "Closed";
    }

    std::string sessionStatus;
    if(sessionsSuspended){
        sessionStatus = "Suspended";
    }
    else{
        sessionStatus = "Active";
    }
    std::cout << name << " - " << openStatus<< ", Sessions: " << sessionStatus<< ", Running: " << currentGame << std::endl;
}

int PCStation::getCapacity() const {
    if(sessionsSuspended){
        return 0;
    }
    else{
        return capacity;
    }
}

void PCStation::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::EVACUATE:
            close();
            break;
        case NoticeType::CAPACITY_ALERT:
            sessionsSuspended = true;
            break;
        case NoticeType::RESUME:
            sessionsSuspended = false;
            break;
        case NoticeType::WEATHER_ALERT:
            // indoor unit
            break;
        default:
            break;
    }
}

void PCStation::setGame(std::string gameName) {
    if(!isOpen){
        return;
    }
    currentGame = gameName;
}
