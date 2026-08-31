#include "MobileStation.h"
#include "Notice.h"
#include <iostream>
#include <algorithm>
using namespace std;

MobileStation::MobileStation(string name, int capacity) : EventUnit(name, capacity), isitopen(false), queueLength(0) {}

void MobileStation::open(){
    isitopen = true;
    cout << name << " Mobile Station rolled into position and is now serving." << endl;
}

void MobileStation::close(){
    isitopen = false;
    queueLength = 0;
    cout << name << " Mobile Station packed up and moved on." << endl;
}

void MobileStation::reportStatus() const{
    cout << name << " - " << (isitopen ? "Open" : "Closed")
         << ", Queue: " << queueLength << " waiting" << endl;
}

int MobileStation::getCapacity() const {
    if (!isitopen) return 0;
    int remaining = capacity - queueLength;
    return remaining > 0 ? remaining : 0;
}

void MobileStation::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::SCHEDULE_CHANGE: {
            int redirected = min(queueLength, notice.value);
            queueLength -= redirected;
            cout << name << " reshuffled its queue, redirecting " << redirected
                 << " attendees elsewhere." << endl;
            break;
        }
        case NoticeType::WEATHER_ALERT:
            queueLength = 0;
              cout << name << " is relocating away from the weather so the queue cleared, "
                 << "still open elsewhere." << endl;
            break;
        case NoticeType::EVACUATE: close();
            break;
           default:
            break;
    }
}
void MobileStation::joinQueue(){
    if(isitopen){
        queueLength++;
          cout << name << " queue grew to " << queueLength << "." << endl;
    } else {
        cout << name << " is closed!" << endl;
    }
}

void MobileStation::leaveQueue(){
    if(queueLength > 0) {
     queueLength--;
        cout << name << " queue shrank to " << queueLength << "." << endl;
    }
}
