#include "VRBooth.h"
#include "Notice.h"
#include <iostream>
using namespace std;

VRBooth::VRBooth(string name, int capacity) : EventUnit(name, capacity), isOpen(false), inCooldown(false) {}

void VRBooth::open() {
    if (inCooldown) {
        cout << name << " cannot start a new Session (is cooling down)." << endl;
        return;
    }
    isOpen = true;
    cout << name << " started a new VR session." << endl;
}

void VRBooth::close() {
    isOpen = false;
    inCooldown = true;
    cout << name << " ended its session and entered cooldown for cleaning." << endl;
}

void VRBooth::reportStatus() const{
       if(isOpen) cout << name << " - Session In Progress" << endl;
     else if(inCooldown) cout << name << " - Cooling Down" << endl;
    else cout << name << " - Closed" << endl;
}

int VRBooth::getCapacity() const {
      return(isOpen && !inCooldown) ? capacity : 0;
}

void VRBooth::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::CAPACITY_ALERT:
            inCooldown = true;
     cout << name << " paused new sessions" << endl;
            break;
          case NoticeType::RESUME:
            inCooldown = false;
            cout << name << " is ready for new sessions again." << endl;
            break;
        case NoticeType::EVACUATE:
            isOpen = false;
               inCooldown = true;
            cout << name << " force-ended its session." << endl;
            break;
        default:
            break;
    }
}
