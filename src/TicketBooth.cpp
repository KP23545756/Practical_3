#include "TicketBooth.h"
#include "Notice.h"
#include <iostream>
using namespace std;

TicketBooth::TicketBooth(string name, int capacity)
    : EventUnit(name, capacity), salesOpen(false), lockedByEvacuation(false) {}

void TicketBooth::open() {
    if (lockedByEvacuation) {
        cout << name << " refuses to reopen - locked since the evacuation, awaiting RESUME." << endl;
        return;
    }
    salesOpen = true;
    cout << name << " is now selling tickets." << endl;
}

void TicketBooth::close() {
    salesOpen = false;
    cout << name << " has stopped selling tickets." << endl;
}

void TicketBooth::reportStatus() const {
    cout << name << " - " << (salesOpen ? "Selling" : "Not Selling") << (lockedByEvacuation ? " (LOCKED - evacuation)" : "") << endl;
}

int TicketBooth::getCapacity() const {
       return (salesOpen && !lockedByEvacuation) ? capacity : 0;
}

void TicketBooth::update(const Notice& notice) {
      switch (notice.type) {
        case NoticeType::EVACUATE:
               salesOpen = false;
            lockedByEvacuation = true;
            cout << name << " halted all sales immediately and locked its window." << endl;
            break;
        case NoticeType::RESUME:
            lockedByEvacuation = false;
               cout << name << " unlocked, selling can resume" << endl;
            break;
        case NoticeType::CAPACITY_ALERT:
            salesOpen = false;
            cout << name << " paused sales due to a capacity alert." << endl;
            break;
        default:
            break;
    }
}
