#include "Subject.h"
#include "Notice.h"

void Subject::attach(Observer* observer) {
    if (observer == NULL) {
        return;
    }
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            return; // already registered, no-op
        }
    }
    observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            return;
        }
    }
}

void Subject::notify(const Notice& notice) {
    std::vector<Observer*> snapshot = observers; // copy first, see class docs
    for (std::vector<Observer*>::iterator it = snapshot.begin(); it != snapshot.end(); ++it) {
        Observer* o = *it;
        o->update(notice);
    }
}

Subject::~Subject() {
    observers.clear(); // never delete: Subject does not own these pointers
}