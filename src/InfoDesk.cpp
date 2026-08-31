#include "InfoDesk.h"
#include "Notice.h"
#include <iostream>
using namespace std;

InfoDesk::InfoDesk(string name, int capacity, string initialAnnoucement) : EventUnit(name, capacity), fullyStaffed(true), announcement(initialAnnoucement) {}

void InfoDesk::open() {
    fullyStaffed = true;
    cout << name << " is now fully staffed." << endl;
}

void InfoDesk::close() {
    fullyStaffed = false;
    cout << name << " is at skeleton crew but remains staffed." << endl;
}

void InfoDesk::reportStatus() const {
           cout << name << " - " << (fullyStaffed ? "Fully Staffed" : "Skeleton Crew")
            << "Board reads: \"" << announcement << "\"" << endl;
}

int InfoDesk::getCapacity() const{
    return fullyStaffed ? capacity : capacity / 2;
}

void InfoDesk::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::OPEN:
            announcement = "Doors are open! " + notice.message;
            break;
        case NoticeType::CLOSE:
            announcement = "Area closing: " + notice.message;
            break;
        case NoticeType::SCHEDULE_CHANGE:
            announcement = "Schedule update: " + notice.message;
            break;
        case NoticeType::CAPACITY_ALERT:
            announcement = "Capacity notice: " + notice.message;
            break;
        case NoticeType::WEATHER_ALERT:
            announcement = "Weather advisory: " + notice.message;
            break;
        case NoticeType::PAUSE:
            announcement = "Temporary pause: " + notice.message;
            break;
        case NoticeType::RESUME:
            announcement = "We're back: " + notice.message;
            break;
        case NoticeType::EVACUATE:
            announcement = "EVACUATE: " + notice.message;
            fullyStaffed = false;
            break;
         default:
            announcement = notice.message;
            break;
    }
    cout << name << " updated the announcement board." << endl;
}
