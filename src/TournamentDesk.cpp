#include "TournamentDesk.h"
#include "Notice.h"
#include <iostream>
using namespace std;

TournamentDesk::TournamentDesk(string name, int capacity, int startingRound): EventUnit(name, capacity), isOpen(true), currentRound(startingRound) {}

void TournamentDesk::open(){
        isOpen = true;
    cout << name << " is open, Round " << currentRound << " underway." << endl;
}

void TournamentDesk::close(){
    isOpen = false;
    cout << name << " has closed between matches." << endl;
}

void TournamentDesk::reportStatus() const {
    cout << name << " - Round " << currentRound << " - "
         << (isOpen ? "In Progress" : "Closed") << endl;
}

int TournamentDesk::getCapacity() const{
    return isOpen ? capacity : 0;
}

void TournamentDesk::update(const Notice& notice) {
    switch(notice.type) {
        case NoticeType::SCHEDULE_CHANGE:
              isOpen = false;
            cout << name << " - next match delayed, desk closed for rescheduling." << endl;
               break;
          case NoticeType::EVACUATE:
            isOpen = false;
            cout << name << " - bracket suspended, evacuating Tournament Zone." << endl;
            break;
        case NoticeType::RESUME:
            isOpen = true;
          cout << name << " - reopening, Round " << currentRound << " resumes." << endl;
            break;
        default:
            break;
    }
}

void TournamentDesk::advanceRound() {
      currentRound++;
    cout << name << " advanced to Round " << currentRound << "." << endl;
}
