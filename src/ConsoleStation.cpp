#include "ConsoleStation.h"
#include "Notice.h"
#include <iostream>

ConsoleStation::ConsoleStation(std::string name, int capacity): EventUnit(name, capacity), isOpen(false),signUpsCapped(false), activeSessions(0){}

void ConsoleStation::open(){
    isOpen = true;
    signUpsCapped = false;
}

void ConsoleStation::close(){
    if(activeSessions > 0){
        std::cout << "  " << name << " saving " << activeSessions<< " active session(s) before shutdown." << std::endl;
        activeSessions = 0;
    }
    isOpen = false;
}

void ConsoleStation::reportStatus() const{
    std::string openStatus;
    if(isOpen){
        openStatus = "Open";
    }
    else{
        openStatus = "Closed";
    }

    std::string signUpStatus;
    if(signUpsCapped){
        signUpStatus = "Capped";
    }
    else{
        signUpStatus = "Open";
    }
    std::cout << name << " - " << openStatus<< ", Sign-ups: " << signUpStatus<< ", Active sessions: " << activeSessions << std::endl;
}

int ConsoleStation::getCapacity() const{
    if(signUpsCapped){
        return capacity / 2;
    }
    else{
        return capacity;
    }
}

void ConsoleStation::update(const Notice& notice){
    switch(notice.type){
        case NoticeType::CAPACITY_ALERT:
            signUpsCapped = true;
            break;
        case NoticeType::RESUME:
            signUpsCapped = false;
            break;
        case NoticeType::EVACUATE:
            close();
            break;
        default:
            break;
    }
}

void ConsoleStation::startSession(){
    activeSessions++;
}

void ConsoleStation::endSession(){
    if(activeSessions > 0){
        activeSessions--;
    }
}
