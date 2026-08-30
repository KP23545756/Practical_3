#include "EventGroup.h"
#include "Notice.h"
#include <iostream>

EventGroup::EventGroup(std::string groupName) : EventComponent(groupName, 0){}

void EventGroup::addChildren(EventComponent* child){
    if (child == NULL){
        return;
    }
    children.push_back(child);
}

EventComponent* EventGroup::removeChildren(EventComponent* child){
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it){
        if (*it == child){
            children.erase(it);
            Observer* asObserver = dynamic_cast<Observer*>(child);
            if (asObserver != NULL){
                detach(asObserver); // only removes it if it was actually registered
            }
            return child; // ownership handed back to caller, not deleted
        }
    }
    return NULL;
}

void EventGroup::open(){
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it){
        EventComponent* c = *it;
        c->open();
    }
}

void EventGroup::close(){
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it){
        EventComponent* c = *it;
        c->close();
    }
}

void EventGroup::reportStatus() const{
    std::cout << "[Group] " << name << std::endl;
    for (std::vector<EventComponent*>::const_iterator it = children.begin(); it != children.end(); ++it){
        EventComponent* c = *it;
        c->reportStatus();
    }
}

int EventGroup::getCapacity() const{
    int total = 0;
    for (std::vector<EventComponent*>::const_iterator it = children.begin(); it != children.end(); ++it){
        EventComponent* c = *it;
        total += c->getCapacity();
    }
    return total;
}

void EventGroup::update(const Notice& notice){
    std::cout << "  [" << name << "] received notice: " << notice.message << std::endl;
    notify(notice); // cascade the same notice to this group's own registered observers
}

EventGroup::~EventGroup(){
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it){
        EventComponent* c = *it;
        Observer* asObserver = dynamic_cast<Observer*>(c);
        if (asObserver != NULL){
            detach(asObserver);
        }
        delete c;
    }
}